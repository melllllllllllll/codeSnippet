#include <stdio.h>

#define TABLE_ROWS 4
#define TABLE_COLS 4

struct Point {
    int x;
    int y;
};

struct Direction {
    int x;
    int y;
};

// this program is suitable for "table" with rows equal to cols
static char table[ TABLE_ROWS ][ TABLE_COLS ] = {
                    { 't', 'h', 'i', 's', },
                    { 'w', 'a', 't', 's', },
                    { 'o', 'a', 'h', 'g', },
                    { 'f', 'g', 'd', 't', },
};

void addJudgePrint( struct Point point, struct Direction direction, int count ) {
    struct Point res = { point.x + direction.x * count, point.y + direction.y * count };
    if( res.x < 0 || res.x > TABLE_ROWS - 1 || res.y < 0 || res.y > TABLE_COLS - 1 ) {
        return;
    }
    for( int i = 0; i <= count; i++ ) {
        printf( "%c", table[ point.x + direction.x * i ][ point.y + direction.y * i ] );
    }
    printf( "\n" );
}

int main( int argc, char *argv[] ) {
    struct Point tmpPoint;
    struct Direction tmpDirection;

    for( int row = 0; row < TABLE_ROWS; row++ ) {
        for( int col = 0; col < TABLE_COLS; col++ ) {

            tmpPoint.x = row;
            tmpPoint.y = col;

            // for (0, 1)
            for( int i = 1; i < TABLE_ROWS; i++ ) {
                tmpDirection.x = 0;
                tmpDirection.y = 1;
                addJudgePrint( tmpPoint, tmpDirection, i );
            }
            // for (1, 1)
            for( int i = 1; i < TABLE_ROWS; i++ ) {
                tmpDirection.x = 1;
                tmpDirection.y = 1;
                addJudgePrint( tmpPoint, tmpDirection, i );
            }
            // for (1, 0)
            for( int i = 1; i < TABLE_ROWS; i++ ) {
                tmpDirection.x = 1;
                tmpDirection.y = 0;
                addJudgePrint( tmpPoint, tmpDirection, i );
            }
            // for (1, -1)
            for( int i = 1; i < TABLE_ROWS; i++ ) {
                tmpDirection.x = 1;
                tmpDirection.y = -1;
                addJudgePrint( tmpPoint, tmpDirection, i );
            }
            // for (0, -1)
            for( int i = 1; i < TABLE_ROWS; i++ ) {
                tmpDirection.x = 0;
                tmpDirection.y = -1;
                addJudgePrint( tmpPoint, tmpDirection, i );
            }
            // for (-1, -1)
            for( int i = 1; i < TABLE_ROWS; i++ ) {
                tmpDirection.x = -1;
                tmpDirection.y = -1;
                addJudgePrint( tmpPoint, tmpDirection, i );
            }
            // for (-1, 0)
            for( int i = 1; i < TABLE_ROWS; i++ ) {
                tmpDirection.x = -1;
                tmpDirection.y = 0;
                addJudgePrint( tmpPoint, tmpDirection, i );
            }
            // for (-1, 1)
            for( int i = 1; i < TABLE_ROWS; i++ ) {
                tmpDirection.x = -1;
                tmpDirection.y = 1;
                addJudgePrint( tmpPoint, tmpDirection, i );
            }
        }
    }

    return 0;
}
