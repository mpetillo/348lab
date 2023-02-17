#include <stdio.h>
#include <string.h>

/*five possible modifiers:
Touchdown + conversion = 8
Touchdown + field goal = 7
Touchdown = 6
Field Goal = 3
Safety = 2*/

void scores(int num){
    int touchdowncon = 0;
    while (touchdowncon * 8 <= num){
        int touchdownfield = 0;
        while ((touchdowncon*8) + (touchdownfield*7) <= num){
            int touchdown = 0;
            while ((touchdowncon*8) + (touchdownfield*7) + (touchdown*6) <= num){
                int fieldgoal = 0;
                while ((touchdowncon*8) + (touchdownfield*7) + (touchdown*6) + (fieldgoal*3) <= num){
                    int safety = 0;
                    while ((touchdowncon*8) + (touchdownfield*7) + (touchdown*6) + (fieldgoal*3) + (safety*2) <= num){
                        if ((touchdowncon*8) + (touchdownfield*7) + (touchdown*6) + (fieldgoal*3) + (safety*2) == num){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", touchdowncon, touchdownfield, touchdown, fieldgoal, safety);
                        }
                        safety++;
                    }
                    fieldgoal++;
                }
                touchdown++;
            }
            touchdownfield++;
        }
        touchdowncon++;
    }
}

int main(){
    int enteredscore = 2;
    printf("Enter 0 or 1 to quit!\n");
    while (enteredscore != 0 && enteredscore != 1){
        printf("Enter a score: ");
        scanf("%d", &enteredscore);
        printf("\n");
        if (enteredscore != 0 && enteredscore != 1){
            scores(enteredscore);
        }
    }
}