#include <stdio.h>

void find_combinations(int score, int td, int fg, int safety, int td_2pt);

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        if (score < 0) {
            printf("Invalid input: Score must be a non-negative integer.\n");
            continue;
        }
        
        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        find_combinations(score, 0, 0, 0, 0);
        printf("\n");
    }

    return 0;
}

void find_combinations(int score, int td, int fg, int safety, int td_2pt) {
    if (score < 0) return; 
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td, td, fg, safety);
        return;
    }

    find_combinations(score - 6, td + 1, fg, safety, td_2pt); // Touchdown
    find_combinations(score - 3, td, fg + 1, safety, td_2pt); // Field Goal
    find_combinations(score - 2, td, fg, safety + 1, td_2pt); // Safety
    find_combinations(score - 8, td, fg, safety, td_2pt + 1); // TD + 2pt conversion
    find_combinations(score - 7, td, fg, safety, td_2pt + 1); // TD + 1pt conversion
}
