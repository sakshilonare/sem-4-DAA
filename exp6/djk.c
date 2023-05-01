#include <stdio.h>
#define MAX 10

void djk(int G[10][10],int n,int start)
{
     int c[10][10],pred[10],dist[10];
     int mindist, visited[10], count,nnode;
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
               if(G[i][j]==0)
               {c[i][j]=999;}
               else
               {
                    c[i][j]=G[i][j];
               }
          }
     }
     for(int i=0;i<n;i++)
     {
          dist[i]=c[start][i];
          pred[i]=start;
          visited[i]=0;
     
     }
     dist[start]=0;
	visited[start]=1;
	count=1;
	while(count < n-1){
		mindist=999;
		for(int i=0;i < n;i++)
			if(dist[i] < mindist&&!visited[i])
			{
				mindist=dist[i];
				nnode=i;
			}
		visited[nnode]=1;
		for(int i=0;i < n;i++)
			if(!visited[i])
				if(mindist+c[nnode][i] < dist[i])
				{
					dist[i]=mindist+c[nnode][i];
					pred[i]=nnode;
				}
			count++;
	}
 
	for(int i=0;i < n;i++)
		if(i!=start)
		{
			printf("\nDistance of %d = %d", i, dist[i]);
			printf("\nPath = %d\n", i);
			int j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=start);
		}
}
 
 void main()
{
 int G[10][10],i,j,n,s;
 printf("Enter the no of vertices: \n");
 scanf("%d",&n);
 printf("\nEnter the adjacency matrix: \n");
 for(i=0;i<n;i++)
     {
          printf("Vertex %d:",i+1);    
          for(j=0;j<n;j++){
          scanf("%d",&G[i][j]);}
     }
 printf("\nEnter the starting vertex:\n");
 scanf("%d",&s);
 djk(G,n,s);    

}
