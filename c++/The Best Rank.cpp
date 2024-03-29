/*
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algrbra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (≤2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output Specification:
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output N/A.

Sample Input:
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output:
1 C
1 M
1 E
1 A
3 A
N/A
*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int id,best;
    int score[4],rank[4];
}stu[2005];
int exist[1000000],flag = -1;
bool cmp1(node a, node b){return a.score[flag] > b.score[flag];}
int main(){
    int n,m,id;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2],&stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0 + 0.5;
        }
        for(flag = 0;flag <= 3;flag++){
            sort(stu,stu+n,cmp1);
            stu[0].rank[flag] = 1;
            for(int i =1;i<n;i++){
                stu[i].rank[flag]=i+1;
            if(stu[i].score[flag]==stu[i-1].score[flag])
            stu[i].rank[flag] = stu[i-1].rank[flag];
        }
        }
for(int i=0;i<n;i++){
    exist[stu[i].id]=i+1;
    stu[i].best=0;
    int minn=stu[i].rank[0];
    for(int j=1;j<=3;j++){
        if(stu[i].rank[j]<minn){
            minn=stu[i].rank[j];
            stu[i].best=j;
        }
    }
}
char c[5]={'A','C','M','E'};
for(int i=0;i<m;i++){
    scanf("%d",&id);
    int temp = exist[id];
    if(temp){
        int best = stu[temp-1].best;
        printf("%d %c\n",stu[temp-1].rank[best],c[best]);
    }else{
        printf("N/A\n");
    }
}
return 0;
}
