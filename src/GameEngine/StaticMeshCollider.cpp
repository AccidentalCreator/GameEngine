#include "StaticMeshCollider.h"
#include "VertexArray.h"
#include "Entity.h"
#include "MeshRenderer.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

// ASK KARSTEN WHAT MAGIC HE USED TO USE THIS LINE
//int triBoxOverLap(float _colCentre[3], float _halfColSize[3], float triVerts[3][3]);

#pragma region Tomas Akenine-Moller



/********************************************************/
/* AABB-triangle overlap test code                      */
/* by Tomas Akenine-Möller                              */
/* Function: int triBoxOverlap(float boxcenter[3],      */
/*          float boxhalfsize[3],float triverts[3][3]); */
/* History:                                             */
/*   2001-03-05: released the code in its first version */
/*   2001-06-18: changed the order of the tests, faster */
/*                                                      */
/* Acknowledgement: Many thanks to Pierre Terdiman for  */
/* suggestions and discussions on how to optimize code. */
/* Thanks to David Hunt for finding a ">="-bug!         */
/********************************************************/

#define X 0
#define Y 1
#define Z 2

#define CROSS(dest,v1,v2) \
          dest[0]=v1[1]*v2[2]-v1[2]*v2[1]; \
          dest[1]=v1[2]*v2[0]-v1[0]*v2[2]; \
          dest[2]=v1[0]*v2[1]-v1[1]*v2[0]; 

#define DOT(v1,v2) (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])

#define SUB(dest,v1,v2) \
          dest[0]=v1[0]-v2[0]; \
          dest[1]=v1[1]-v2[1]; \
          dest[2]=v1[2]-v2[2]; 

#define FINDMINMAX(x0,x1,x2,min,max) \
  min = max = x0;   \
  if(x1<min) min=x1;\
  if(x1>max) max=x1;\
  if(x2<min) min=x2;\
  if(x2>max) max=x2;

int planeBoxOverlap(float normal[3], float vert[3], float maxbox[3])	// -NJMP-
{
	int q;
	float vmin[3], vmax[3], v;
	for (q = X; q <= Z; q++)
	{
		v = vert[q];					// -NJMP-
		if (normal[q]>0.0f)
		{
			vmin[q] = -maxbox[q] - v;	// -NJMP-
			vmax[q] = maxbox[q] - v;	// -NJMP-
		}
		else
		{
			vmin[q] = maxbox[q] - v;	// -NJMP-
			vmax[q] = -maxbox[q] - v;	// -NJMP-
		}
	}
	if (DOT(normal, vmin)>0.0f) return 0;	// -NJMP-
	if (DOT(normal, vmax) >= 0.0f) return 1;	// -NJMP-

	return 0;
}


/*======================== X-tests ========================*/
#define AXISTEST_X01(a, b, fa, fb)			   \
	p0 = a*v0[Y] - b*v0[Z];			       	   \
	p2 = a*v2[Y] - b*v2[Z];			       	   \
        if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;} \
	rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];   \
	if(min>rad || max<-rad) return 0;

#define AXISTEST_X2(a, b, fa, fb)			   \
	p0 = a*v0[Y] - b*v0[Z];			           \
	p1 = a*v1[Y] - b*v1[Z];			       	   \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
	rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];   \
	if(min>rad || max<-rad) return 0;

/*======================== Y-tests ========================*/
#define AXISTEST_Y02(a, b, fa, fb)			   \
	p0 = -a*v0[X] + b*v0[Z];		      	   \
	p2 = -a*v2[X] + b*v2[Z];	       	       	   \
        if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;} \
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];   \
	if(min>rad || max<-rad) return 0;

#define AXISTEST_Y1(a, b, fa, fb)			   \
	p0 = -a*v0[X] + b*v0[Z];		      	   \
	p1 = -a*v1[X] + b*v1[Z];	     	       	   \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];   \
	if(min>rad || max<-rad) return 0;

/*======================== Z-tests ========================*/

#define AXISTEST_Z12(a, b, fa, fb)			   \
	p1 = a*v1[X] - b*v1[Y];			           \
	p2 = a*v2[X] - b*v2[Y];			       	   \
        if(p2<p1) {min=p2; max=p1;} else {min=p1; max=p2;} \
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];   \
	if(min>rad || max<-rad) return 0;

#define AXISTEST_Z0(a, b, fa, fb)			   \
	p0 = a*v0[X] - b*v0[Y];				   \
	p1 = a*v1[X] - b*v1[Y];			           \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];   \
	if(min>rad || max<-rad) return 0;

int triBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3])
{

	/*    use separating axis theorem to test overlap between triangle and box */
	/*    need to test for overlap in these directions: */
	/*    1) the {x,y,z}-directions (actually, since we use the AABB of the triangle */
	/*       we do not even need to test these) */
	/*    2) normal of the triangle */
	/*    3) crossproduct(edge from tri, {x,y,z}-directin) */
	/*       this gives 3x3=9 more tests */
	float v0[3], v1[3], v2[3];
	//   float axis[3];
	float min, max, p0, p1, p2, rad, fex, fey, fez;		// -NJMP- "d" local variable removed
	float normal[3], e0[3], e1[3], e2[3];

	/* This is the fastest branch on Sun */
	/* move everything so that the boxcenter is in (0,0,0) */
	SUB(v0, triverts[0], boxcenter);
	SUB(v1, triverts[1], boxcenter);
	SUB(v2, triverts[2], boxcenter);

	/* compute triangle edges */
	SUB(e0, v1, v0);      /* tri edge 0 */
	SUB(e1, v2, v1);      /* tri edge 1 */
	SUB(e2, v0, v2);      /* tri edge 2 */

						  /* Bullet 3:  */
						  /*  test the 9 tests first (this was faster) */
	fex = fabsf(e0[X]);
	fey = fabsf(e0[Y]);
	fez = fabsf(e0[Z]);
	AXISTEST_X01(e0[Z], e0[Y], fez, fey);
	AXISTEST_Y02(e0[Z], e0[X], fez, fex);
	AXISTEST_Z12(e0[Y], e0[X], fey, fex);

	fex = fabsf(e1[X]);
	fey = fabsf(e1[Y]);
	fez = fabsf(e1[Z]);
	AXISTEST_X01(e1[Z], e1[Y], fez, fey);
	AXISTEST_Y02(e1[Z], e1[X], fez, fex);
	AXISTEST_Z0(e1[Y], e1[X], fey, fex);

	fex = fabsf(e2[X]);
	fey = fabsf(e2[Y]);
	fez = fabsf(e2[Z]);
	AXISTEST_X2(e2[Z], e2[Y], fez, fey);
	AXISTEST_Y1(e2[Z], e2[X], fez, fex);
	AXISTEST_Z12(e2[Y], e2[X], fey, fex);

	/* Bullet 1: */
	/*  first test overlap in the {x,y,z}-directions */
	/*  find min, max of the triangle each direction, and test for overlap in */
	/*  that direction -- this is equivalent to testing a minimal AABB around */
	/*  the triangle against the AABB */

	/* test in X-direction */
	FINDMINMAX(v0[X], v1[X], v2[X], min, max);
	if (min>boxhalfsize[X] || max<-boxhalfsize[X]) return 0;

	/* test in Y-direction */
	FINDMINMAX(v0[Y], v1[Y], v2[Y], min, max);
	if (min>boxhalfsize[Y] || max<-boxhalfsize[Y]) return 0;

	/* test in Z-direction */
	FINDMINMAX(v0[Z], v1[Z], v2[Z], min, max);
	if (min>boxhalfsize[Z] || max<-boxhalfsize[Z]) return 0;

	/* Bullet 2: */
	/*  test if the box intersects the plane of the triangle */
	/*  compute plane equation of triangle: normal*x+d=0 */
	CROSS(normal, e0, e1);
	// -NJMP- (line removed here)
	if (!planeBoxOverlap(normal, v0, boxhalfsize)) return 0;	// -NJMP-

	return 1;   /* box and triangle overlaps */
}

#pragma endregion

void StaticMeshCollider::Start()
{
	noOfColumns = 10;
	tryStep = 0.001f;
	maxStep = 1.0f;
	increment = 0.01f;
	maxIncrement = 0.5f;

	std::shared_ptr<MeshRenderer> meshRenderer = GetEntity()->GetComponent<MeshRenderer>();
	std::shared_ptr<VertexArray> meshData = meshRenderer->GetMeshData();
	FindSizeOfModel();

	// Create Partioned Columns
	glm::vec3 meshSize = size.maxCoord - size.minCoord;
	glm::vec3 columnSize = meshSize / noOfColumns;
	columnSize.y = meshSize.y; // Top of column is top of model

	for (size_t y = 0; y < noOfColumns; y++)
	{
		// Set position to middle of columns
		glm::vec3 position = size.minCoord + columnSize / 2.0f;
		position.z += (float)y * columnSize.z;

		for (size_t x = 0; x < noOfColumns; x++)
		{
			std::shared_ptr<PartitioningColumn> column = std::make_shared<PartitioningColumn>();
			column->size = columnSize;
			column->position = position;
			columns.push_back(column);
			position.x += columnSize.x;
		}
	}

	// Add faces to vector of faces
	for (size_t i = 0; i < meshData->faces.size(); i++)
	{
		Face face = meshData->faces.at(i);
		AddFace(face);
	}
}

void StaticMeshCollider::FindSizeOfModel()
{
	std::vector<glm::vec3> positions;
	std::shared_ptr<MeshRenderer> meshRenderer = GetEntity()->GetComponent<MeshRenderer>();
	std::shared_ptr<VertexArray> meshData = meshRenderer->GetMeshData();

	// Place all the vertex position data into the positions vector
	for (size_t i = 0; i < meshData->faces.size(); i++)
	{
		Face face = meshData->faces.at(i);
		positions.push_back(face.a.position);
		positions.push_back(face.b.position);
		positions.push_back(face.c.position);
	}

	// Assign positions of first face
	size.maxCoord = positions.at(0);
	size.minCoord = positions.at(0);

	for (size_t i = 1; i < positions.size(); i++)
	{
		// Check max position
		if (positions.at(i).x > size.maxCoord.x)
			size.maxCoord.x = positions.at(i).x;
		if (positions.at(i).y > size.maxCoord.y)
			size.maxCoord.y = positions.at(i).y;
		if (positions.at(i).z > size.maxCoord.z)
			size.maxCoord.z = positions.at(i).z;

		// Check min positions
		if (positions.at(i).x < size.minCoord.x)
			size.minCoord.x = positions.at(i).x;
		if (positions.at(i).y < size.minCoord.y)
			size.minCoord.y = positions.at(i).y;
		if (positions.at(i).z < size.minCoord.z)
			size.minCoord.z = positions.at(i).z;
	}

	// Not Sure why this
	size.minCoord = size.minCoord - glm::vec3(1, 1, 1);
	size.maxCoord = size.maxCoord + glm::vec3(1, 1, 1);
}

bool StaticMeshCollider::Colliding(glm::vec3 _position, glm::vec3 _size)
{
	glm::vec3 position = _position - size.minCoord;
	size_t x = (size_t)(position.x / columns.at(0)->size.x);
	size_t y = (size_t)(position.z / columns.at(0)->size.z);
	size_t index = y * noOfColumns + x;

	if (index >= columns.size())
	{
		return false;
	}

	if (columns.at(index)->Colliding(_position, _size))
	{
		return true;
	}
	
	return false;
}

void StaticMeshCollider::AddFace(Face _face)
{
	float face[3][3] = { 0 };
	face[0][0] = _face.a.position.x;
	face[0][1] = _face.a.position.y;
	face[0][2] = _face.a.position.z;

	face[1][0] = _face.b.position.x;
	face[1][1] = _face.b.position.y;
	face[1][2] = _face.b.position.z;

	face[2][0] = _face.c.position.x;
	face[2][1] = _face.c.position.y;
	face[2][2] = _face.c.position.z;

	bool faceFound = false;

	for (size_t i = 0; i < columns.size(); i++)
	{
		// Not sure what stands for
		float columnCentre[3] = { 0 };
		columnCentre[0] = columns.at(i)->position.x;
		columnCentre[1] = columns.at(i)->position.y;
		columnCentre[2] = columns.at(i)->position.z;

		// Sub collumns overlap
		glm::vec3 subColumn = columns.at(i)->size;
		subColumn.x += 1;
		subColumn.z += 1;

		float halfColumnSize[3] = { 0 };
		halfColumnSize[0] = subColumn.x / 2.0f;
		halfColumnSize[1] = subColumn.y / 2.0f;
		halfColumnSize[2] = subColumn.z / 2.0f;

		if (triBoxOverlap(columnCentre, halfColumnSize, face))
		{
			columns.at(i)->faces.push_back(_face);
			faceFound = true;
		}
	}

	if (!faceFound)
	{
		throw std::exception();
	}
}

bool PartitioningColumn::Colliding(glm::vec3 _position, glm::vec3 _size)
{
	for (int i = 0; i < faces.size(); i++)
	{
		float face[3][3] = { 0 };
		face[0][0] = faces.at(i).a.position.x;
		face[0][1] = faces.at(i).a.position.y;
		face[0][2] = faces.at(i).a.position.z;

		face[1][0] = faces.at(i).b.position.x;
		face[1][1] = faces.at(i).b.position.y;
		face[1][2] = faces.at(i).b.position.z;

		face[2][0] = faces.at(i).c.position.x;
		face[2][1] = faces.at(i).c.position.y;
		face[2][2] = faces.at(i).c.position.z;

		float columnCentre[3] = { 0 };
		columnCentre[0] = _position.x;
		columnCentre[1] = _position.y;
		columnCentre[2] = _position.z;

		float halfColumnSize[3] = { 0 };
		halfColumnSize[0] = _size.x / 2.0f;
		halfColumnSize[1] = _size.y / 2.0f;
		halfColumnSize[2] = _size.z / 2.0f;

		if (triBoxOverlap(columnCentre, halfColumnSize, face))
		{
			return true;
		}
	}

	return false;
}


glm::vec3 StaticMeshCollider::CollisionAdjustment(glm::vec3 _position, glm::vec3 _size, bool & _solved, glm::vec3 _lastPosition)
{
	glm::vec3 solve = _position;
	float amount = tryStep;

	_solved = true;

	if (!Colliding(solve, _size))
	{
		collidingY = false;
		return solve;
	}

	_solved = true;

	// Uncollide in Y
	while (true)
	{
		solve.y += amount;
		if (!Colliding(solve, _size))
		{
			break;
		}
		solve.y -= amount;
		amount += tryStep;

		if (amount > maxStep)
		{
			_solved = false;
			break;
		}
	}

	if (_solved)
	{
		uncollideY = solve.y;
		collidingY = true;
		return solve;
	}

	_solved = true;
	amount = increment;

	solve = _position; // Setting solve back to position Why does it still increase;

	// Uncollide in x/z
	while (true)
	{
		solve.x += amount;

		if (!Colliding(solve, _size))
		{
			break;
		}

		solve.x -= amount;
		solve.x -= amount;

		if (!Colliding(solve, _size))
		{
			break;
		}

		solve.x += amount;
		solve.z += amount;

		if (!Colliding(solve, _size))
		{
			break;
		}

		solve.z -= amount;
		solve.z -= amount;

		if (!Colliding(solve, _size))
		{
			break;
		}

		solve.z += amount;

		amount += increment;

		if (amount > maxIncrement)
		{
			_solved = false;
			break;
		}
	}

	if (_solved)
	{
		return solve;
	}
	_solved = true;
	amount = increment;

	// Uncollide in x+z - Corners
	while (true)
	{
		// Top Left
		solve.x -= amount;
		solve.z += amount;

		if (!Colliding(solve, _size))
		{
			break;
		}

		// Top Right
		solve.x += amount;
		solve.x += amount;

		if (!Colliding(solve, _size))
		{
			break;
		}

		// Bottom Right
		solve.z -= amount;
		solve.z -= amount;

		if (!Colliding(solve, _size))
		{
			break;
		}

		// Bottom Left
		solve.x -= amount;
		solve.x -= amount;

		if (!Colliding(solve, _size))
		{
			break;
		}

		solve.z += amount;
		solve.x += amount;
		amount += increment;

		if (amount > maxIncrement)
		{
			_solved = false;
			break;
		}
	}

	return solve;
	
}