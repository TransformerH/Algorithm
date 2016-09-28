//
//  main.cpp
//  chessBoard_non_cpp
//
//  Created by 韩雪滢 on 9/28/16.
//  Copyright © 2016 韩雪滢. All rights reserved.
//
/*
 *解题思路：
 *棋盘覆盖问题，非递归解决方法
 *先填充特殊格子，让每一个4格棋盘都变成3格棋盘
 *再填充3格棋盘
 */

#include<iostream>
using namespace std;
int Board[100][100];
void ChessBoardNonRecursive(int size)
{
    int i,j,dr1,dc1;
    int t=1;
    if (size<4)
    {return ;}
    int sizesub=size/2;
    int sumTmp=0;
    while (sizesub>=2)
    {
        for (i=0;i<size;i=i+sizesub*2)
        {
            for (j=0;j<size;j=j+sizesub*2)
            {
                
                t++;
                
                //左上角的子棋盘
                sumTmp=0;
                for (dr1=0;dr1<sizesub;dr1++)
                {
                    for ( dc1=0;dc1<sizesub;dc1++)
                    {
                        sumTmp+=Board[dr1+i][dc1+j];
                    }
                }
                
                //sumTmp == 0 这块棋盘中没有特殊格子
                if (sumTmp==0)
                {
                    //给这个右下角设为特殊格子
                    Board[i+sizesub-1][j+sizesub-1]=t;
                }
                
                //右上角的子棋盘
                sumTmp=0;
                for (dr1=0;dr1<sizesub;dr1++)
                {
                    for (dc1=0;dc1<sizesub;dc1++)
                    {
                        sumTmp+=Board[dr1+i][dc1+sizesub+j];
                    }
                }
                if (sumTmp==0)
                {
                    Board[i+sizesub-1][j+sizesub]=t;
                }
                
                //左下角的子棋盘
                sumTmp=0;
                for (dr1=0;dr1<sizesub;dr1++)
                {
                    for (dc1=0;dc1<sizesub;dc1++)
                    {
                        sumTmp+=Board[dr1+sizesub+i][dc1+j];
                    }
                }
                if (sumTmp==0)
                {
                    Board[i+sizesub][j+sizesub-1]=t;
                }
                
                
                //右下角的子棋盘
                sumTmp=0;
                for (dr1=0;dr1<sizesub;dr1++)
                {
                    for (dc1=0;dc1<sizesub;dc1++)
                    {
                        sumTmp+=Board[dr1+sizesub+i][dc1+sizesub+j];
                    }
                }
                if (sumTmp==0)
                {
                    Board[i+sizesub][j+sizesub]=t;
                }
            }
        }
        sizesub=sizesub/2;
    }
    
    //  填充其他非特殊方格
    for (i=0;i<size;i=i+2)
    {
        for (j=0;j<size;j=j+2)
        {
            t++;
            
            for (dr1=0;dr1<2;dr1++)
            {
                for (dc1=0;dc1<2;dc1++)
                {
                    if  (Board[dr1+i][dc1+j]==0)
                    {
                        Board[dr1+i][dc1+j]=t;
                    }
                }
            }
        }
    }
}
int main()
{
    int a,b,size;
    Board[100][100]={0};
    cout<<"请输入棋盘的大小"<<endl;
    cin>>size;
    cout<<"请输入特殊方格的坐标"<<endl;
    cin>>a;
    cin>>b;
    Board[a][b]=1;
    cout<<"生成的棋盘输出"<<endl;
    ChessBoardNonRecursive(size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout<<Board[i][j]<<'\t';
        cout<<endl<<endl;
    }
    
    return 0;
}
