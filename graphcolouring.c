#include<stdio.h>
const int max=100;
int a[100][100],color[100],degree[100],NN[100],n,NNcount,unprocessed; 
void getInput()
{
  printf("Enter no of vertex : ");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix : ");
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
          scanf("%d",&a[i][j]);
      }
    }
}
void init()
{
  for(int i=0;i<n;i++)
  {
    color[i]=0;
    degree[i]=0;
    for(int j=0;j<n;j++)
    {
      if(a[i][j]==1)
        degree[i]++;
    }
  }
  NNcount=0;
  unprocessed=n;
}
int MaxDegreeVertex()
{
  int max=-1,max_i;
  for(int i=0;i<n;i++)
  {
    if(color[i]==0)
    {
      if(degree[i]>max)
      {
        max=degree[i];
        max_i=i;
      }
    }
  }
  return (max_i);
}
void scannedinit(int scanned[max])
{
  for(int i=0;i<n-1;i++)
  {
    scanned[i]=0;
  }
}
void UpdateNN(int ColorNumber)
{
  for(int i=0;i<n-1;i++)
  {
    if(color[i]==0)
    {
      NN[NNcount]=i;
      NNcount++;
    }
    for(int i=0;i<n;i++)
    {
      if(color[i]==ColorNumber)
      {
        for(int j=0;i<NNcount;j++)
        {
          while(a[i][NN[j]]==1)
          {
            NN[j]=NN[NNcount-1];
            NNcount--;
          }
        }
      }
    }
  }
}
int find(int ColorNumber, int verticesincommon)
{
  verticesincommon=0;
  int scanned[max];
  for(int i=0;i<NNcount;i++)
  {
    int tmp_y=NN[i];
    int temp=0,y;
    scannedinit(scanned);
    for(int x=0;x<n;x++)
    {
      if(color[x]==ColorNumber)
      {
        for(int k=0;k<n;k++)
        {
          if(color[k]==0 && scanned[k]==0)
          {
            if(a[x][k]==1 && a[tmp_y][k]==1)
            {
              temp++;
              scanned[k]=1;
            }
            if(temp>verticesincommon)
            {
              verticesincommon=temp;
              y=tmp_y;
            }
          }
        }
      }
    }
    return(y);
  }
}
int MaxDegreeInNN()
{
  int tmp_y;
  int max=0;
  for(int i=0;i<NNcount-1;i++)
  {
    int temp=0;
    for(int j=0;j<n-1;j++)
    {
      if(color[NN[j]]==0 && a[i][NN[j]]==1)
      {
        temp++;
      }
    }
    if(temp>max)
    {
      max=temp;
      tmp_y=NN[i];
    }
  }
  return (tmp_y);
}
void colouring()
{
  int x,verticesincommon,ColorNumber=0;
  while(unprocessed>0)
  {
    x=MaxDegreeVertex();
    ColorNumber++;
    color[x]=ColorNumber;
    unprocessed--;
    UpdateNN(ColorNumber);
    while(NNcount>0)
    {
      int y=find(ColorNumber,verticesincommon);
      if(verticesincommon==0)
      {
        y=MaxDegreeInNN();
        color[y]=ColorNumber;
        unprocessed--;
      }
      UpdateNN(ColorNumber);
    }

  }
}
void main()
{
    getInput();
    init();
    colouring();
    for(int i=0;i<n;i++)
      printf("%d->%d\n",i+1,color[i]);
}