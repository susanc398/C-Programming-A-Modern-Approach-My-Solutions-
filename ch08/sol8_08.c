/* For five quiz grades and five students the program computers the total score and average score
   for each student and the average, highest, and lowest scores for each quiz */

#include <stdio.h>

int main(void)
{
    int grades[5][5], student, quiz, grade_sums_per_student[5] = {}, grade_sums_per_quiz[5] = {},
        high_score_per_quiz[5] = {}, low_score_per_quiz[5];
    float grade_avg_per_student[5], grade_avg_per_quiz[5];

    for (student = 0; student < 5; student++) {
        printf("Enter quiz grades for Student %d: ", student + 1);
        for (quiz = 0; quiz < 5; quiz++) {
            scanf("%d", &grades[student][quiz]);

            grade_sums_per_student[student] += grades[student][quiz];
            grade_sums_per_quiz[quiz] += grades[student][quiz];
            if (grades[student][quiz] > high_score_per_quiz[quiz])
                high_score_per_quiz[quiz] = grades[student][quiz];

            if (student == 0)
                low_score_per_quiz[quiz] = grades[student][quiz];
            else 
                if (grades[student][quiz] < low_score_per_quiz[quiz])
                    low_score_per_quiz[quiz] = grades[student][quiz];
        }
        grade_avg_per_student[student] = grade_sums_per_student[student] / 5.0f;
    }

    for (quiz = 0; quiz < 5; quiz++)
        grade_avg_per_quiz[quiz] = grade_sums_per_quiz[quiz] / 5.0f;


    printf("\nTotal score for each student:");
    for (student = 0; student < 5; student++)
        printf(" %d", grade_sums_per_student[student]);

    printf("\nAverage score for each student:");
    for (student = 0; student < 5; student++)
        printf(" %.1f", grade_avg_per_student[student]);

    printf("\nAverage score per quiz:");
    for (quiz = 0; quiz < 5; quiz++)
        printf(" %.1f", grade_avg_per_quiz[quiz]);
    
    printf("\nHighest score per quiz:");
    for (quiz = 0; quiz < 5; quiz++)
        printf(" %d", high_score_per_quiz[quiz]);

    printf("\nLowest score per quiz:");
    for (quiz = 0; quiz < 5; quiz++)
        printf(" %d", low_score_per_quiz[quiz]);
    printf("\n");

    return 0;
}