#include <stdio.h>
#include <stdlib.h>

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize)
{
	int	res = 0;

	int x, y;
	for (int i = 0; i < pointsSize - 1; i++)
	{
		x = abs(points[i + 1][0] - points[i][0]);
		y = abs(points[i + 1][1] - points[i][1]);
		while (x != 0 && y != 0)
		{
			x--;
			y--;
			res++;
		}
		res = res + x + y;
	}
	return (res);
}

int main() {
    int pointsSize = 3;
    int pointsColSize[] = {2, 2, 2};
    int** points = (int**)malloc(pointsSize * sizeof(int*));
    points[0] = (int*)malloc(2 * sizeof(int));
    points[1] = (int*)malloc(2 * sizeof(int));
    points[2] = (int*)malloc(2 * sizeof(int));
    points[0][0] = 1; points[0][1] = 1;
    points[1][0] = 3; points[1][1] = 4;
    points[2][0] = -1; points[2][1] = 0;
    int result = minTimeToVisitAllPoints(points, pointsSize, pointsColSize);
    printf("Minimum time to visit all points: %d\n", result);
    for (int i = 0; i < pointsSize; i++) {
        free(points[i]);
    }
    free(points);
}