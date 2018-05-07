/*
 *  Author:   Alexander Mason
 *  Program:  primesInGrid
 *  Date:     5/7/2018 
 *  Summary:  This puzzle was first proposed (1989) by Gordon Lee: given a grid 
 *            of numbers, how many distinct primes can you find embedded in the 
 *            matrix, regarding that you can read the lines or part of them, in 
 *            form vertical, horizontal or diagonal orientation, in both directions.
 *            Note that you can't change direction once you start moving 
 *            (e.g. this isn't Boggle).
 *
 *  Link: https://www.reddit.com/r/dailyprogrammer/comments/
 *        8gzaz5/20180504_challenge_359_hard_primes_in_grids/
 */


#define SHOW_MATRIX

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool
fermatLittle(int p){  
  //a = any integer not divisible by the number
  //p = the prime in question
  int a = 0;
  while(!(a % p))
    a = rand();
  if(((int)pow((double)a, (double)p) - 1) % p)
    return false;
  return true;
}

int
findPrimes(int N, int grid[N][N]){
  int cnt = 0;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      if(fermatLittle(grid[i][j]))
        ++cnt;
  return cnt;
}

int
main(int argc, char * argv[]){
  int N, arg;
  FILE *fp;
  
  if(argc > 1){
    arg = 1;
    fp = fopen(argv[arg++], "r"); 
    fscanf(fp, "%d", &N);
    printf("\n----------\n%d * %d Matrix\n----------\n", N, N);
    int grid[N][N];
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
        fscanf(fp, "%d", &grid[i][j]);
#ifdef SHOW_MATRIX
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        printf("%d", grid[i][j]);
      }
      printf("\n");
    }
#endif
    printf("\n----------\n%d Primes in Matrix\n----------\n", findPrimes(N, grid));
  }else
    printf("\nEnter a primes file to test.\n");
  return 0;
}

