#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#define infinity 999
#define inf 9999
#define size 10/*Defining maximum size of the matrix*/

int input_left,input_arr[10][2];
int flag=0,cost;
int nodes;
int str=65;
int i=1,j=1;
int adj[10][10];
int menu_id;
int showgraph=0;
char cost_s[2];
static int y,x;
char name = 'A';
int submenu_id,submenu_id1;
int dln;
float r=0.0f,g=0.0f ,b=1.0f;
int cost_p,cost_k,cost_d;//int stage=0;
int wid=0;

void display()
{
glClearColor(1.0f,0.9f,0.8f,1.0f);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0f,0.5f,0.6f);
glFlush();

}

void init( )
{
 glClearColor(1.0f,0.9f,0.8f,1.0f);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.1f,0.5f,0.6f);

}

void reshape(GLsizei WIDTH, GLsizei HEIGHT)
{
glViewport(0,0,WIDTH,HEIGHT);
glMatrixMode(GL_PROJECTION_MATRIX);
glLoadIdentity();
gluOrtho2D(0.0f,320.0f,320.0f,0.0f);
}

void draw_node(int x,int y)
{
 glColor3f(0.0f,0.0f,0.0f);
 glPointSize(1);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();


glRasterPos2i(x,y+1);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(char)str);
glFlush();
str++;
}

void mouse(int button ,int state, int x, int y)
  {
   if(input_left<=nodes)
 {
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
   {
     input_arr[input_left][0]=x;
     input_arr[input_left][1]=y;
     draw_node(input_arr[input_left][0],input_arr[input_left][1]);
     printf("(%d,%d)",x,y);
     input_left++;

    if(input_left == nodes)
      {
printf("STAGE 1 STARTED");
    flag=1;
      }
   }
 }
    else if(flag == 1)
   {
for(int i=0;i<=nodes;i++){
    printf("-->%d<---",input_arr[i][0]);
}
      if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
      {

       printf("left click");
       glColor3f(0.0f,0.0f,1.0f);
       cost=sqrt(pow((input_arr[j][0]-input_arr[i][0]),2)+pow((input_arr[j][1]- input_arr[i][1]),2));
       printf("\n%d\n",cost);

            adj[i][j]=cost;
            adj[j][i]=cost;
            for(int f=1;f<=nodes;f++)
        {
            for(int d=1;d<=nodes;d++){
            printf("%d\t",adj[f][d]);
            }
            printf("\n");
}

       sprintf(cost_s,"%d",cost);
       int midx=(input_arr[i][0]+input_arr[j][0])/2;
       int midy=(input_arr[i][1]+input_arr[j][1])/2;
      printf("cost %s",cost_s);
       glRasterPos2i(midx+1,midy+1);
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(int)cost_s);
       glLineWidth(1);
       glBegin(GL_LINES);
       glVertex2i(input_arr[i][0],input_arr[i][1]);
       glVertex2i(input_arr[j][0],input_arr[j][1]);
       glEnd();
       if(cost!=0)cost_n(cost,midx,midy);

       glFlush();
       j++;

     }
if(i==(nodes))
    {         flag=2;
              createMenu();
              stage3();
    }
  else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
     {
      printf("right click\n");
      j++;
      }
    if(j>nodes){
         i++;
         j=i+1; }


}
}
 void cost_n(int aver,int x,int y){
     int g=0;
                          glColor3f(1.0f,0.0f,0.0f);
                                char vString[50]={"0"};
                                int val=aver;
                                sprintf(vString,"%d",val);
                                   glRasterPos2f(x,y-5);
	                               for(g=0;g<strlen(vString);g++)
                                   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(int)vString[g]);
                                   glFlush();
      }
void stage3()
{

    int i=0;
 char *String="RIGHT CLICK FOR THE OPTIONS";
glRasterPos2f(6.0f,280.0f);
for(i=0;i<strlen(String);i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(int)String[i]);
glFlush();

}

void draw_nod(int x,int y)
{ glColor3f(0.5f,0.2f,0.3f);
  glEnable (GL_POINT_SMOOTH);
  glPointSize(1.0);
  glBegin(GL_POINTS);

  glPointSize(10.0);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

void name_node(char name,int x,int y)
{   glColor3f(0.5f,0.2f,0.3f);
    glRasterPos2f(x,y-5);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)name);
    glFlush();
}


void Prims_d()   //main program
{
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
            printf("Enter the number of nodes:");
//            scanf("%d",&n);
   n=nodes;
   int a1,b1;
   printf("Enter the adjacency matrix:\n");
            for(i=1;i<=n;i++)
            {
                        for(j=1;j<=n;j++)
                        {
                            cost[i][j]=adj[i][j];
                                    if(cost[i][j]==0)
                                    cost[i][j]=999;
                        }
            }
            visited[1]=1;
            printf("\n");
            while(ne<n)
            {
                        for(i=1,min=999;i<=n;i++)
                        {
                                    for(j=1;j<=n;j++)
                                    {
                                                if(cost[i][j]<min)
                                                if(visited[i]!=0)
                                                {
                                                min=cost[i][j];
                                                a=u=i;
                                                b=v=j;
                                                }
                                    }
                        }
                        if(visited[u]==0 || visited[v]==0)
                        {
                                    printf("\nEdge %d:(%d %d) cost:%d",ne++,a,b,min);
                                    mincost+=min;
                                    visited[b]=1;

                                   glColor3f(r,g,b);
                                    visited[b]=1;
                                    if(wid==1){
                                      glLineWidth(10.0f);
                                      }
                                   glBegin(GL_LINES);
                                   glVertex2i(input_arr[a][0],input_arr[a][1]);
                                   glVertex2i(input_arr[b][0],input_arr[b][1]);
                                   glEnd();
                                glFlush();
                        int midx=(input_arr[a][0]+input_arr[b][0])/2;
                        int midy=(input_arr[a][1]+input_arr[b][1])/2;
                        cost_n(min,midx,midy);

             if(a1!=a){
                        name=name+a-1;
                          printf("\n try %c <--",name);
                          draw_nod(input_arr[a][0],input_arr[a][1]);
                          name_node(name,input_arr[a][0],input_arr[a][1]);
                          name='A';
                      }


          if(b1!=b){name=name+b-1;
                          printf("\n try %c <--",name);
                          draw_nod(input_arr[b][0],input_arr[b][1]);
                          name_node(name,input_arr[b][0],input_arr[b][1]);
                          name='A';
          }
          a1=a;
          b1=b;
                        }

                        cost[a][b]=cost[b][a]=999;
            }
           printf("\nMinimun cost=%d",mincost);
            cost_p=mincost;
            name='A';
      wid=0;      }
void dis_Prims()
{
    glClearColor(1.0f,0.9f,0.8f,1.0f);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0f,0.5f,0.6f);

 printf("prims display");
 Prims_d();
 int i=0;
 char *String="GRAPH USING PRIM'S ALGORITHM";
 glRasterPos2f(6.0f,280.0f);
 for(i=0;i<strlen(String);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(int)String[i]);


 glFlush();

}

void Prims()
{
  glutCreateWindow("PRIMS");
  glutInitWindowPosition(50,50);
  glutInitWindowSize(320,320);
  glutReshapeWindow(320,320);
  glutPositionWindow(320,30);
  init();
  glutDisplayFunc(dis_Prims);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
int parent[10];

void Kruskals_d()   //main program
{int i,j,k,a,b,u=0,v=0,n,ne=1;
int min,mincost=0,cost[9][9];
int y=40;
for(i=0;i<9;i++) parent[i]=0;
 printf("\n Implementation of Kruskal's algorithm \n");
 n=nodes;
 printf("\nEnter the cost adjacency matrix");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
    cost[i][j]=adj[i][j];
    if(cost[i][j]==0)
    cost[i][j]=999;
  }
 }
 printf("\nThe edges of Minimum Cost Spanning Tree are");
int a1,b1;
 while(ne<n)
 {
  for(i=1,min=999;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(cost[i][j]<min)
    {
     min=cost[i][j];
     a=u=i;
     b=v=j;

    }
   }
  }
  u=find(u);
  v=find(v);
  if(uni(u,v))
  {
ne=ne+1;
   printf("\n%d edge (%d,%d) =%d",ne,a,b,min);
                                     glColor3f(r,g,b);
                                     if(wid==1){
                                      glLineWidth(5.0f);}
                                     glBegin(GL_LINES);
                                   glVertex2i(input_arr[a][0],input_arr[a][1]);
                                   glVertex2i(input_arr[b][0],input_arr[b][1]);
                                   glEnd();
                                glFlush();
             if(a1!=a){
                        name=name+a-1;
                          draw_nod(input_arr[a][0],input_arr[a][1]);
                          name_node(name,input_arr[a][0],input_arr[a][1]);
                          name='A';
                      }


          if(b1!=b){name=name+b-1;
                          draw_nod(input_arr[b][0],input_arr[b][1]);
                          name_node(name,input_arr[b][0],input_arr[b][1]);
                          name='A';
          }
          a1=a;
          b1=b;
                        int midx=(input_arr[a][0]+input_arr[b][0])/2;
                        int midy=(input_arr[a][1]+input_arr[b][1])/2;
                        cost_n(min,midx,midy);

             mincost +=min;
  }
  cost[a][b]=cost[b][a]=999;
 }

 cost_k = mincost;
 printf("\n Minimum cost = %d",mincost);
 draw_nod(input_arr[b][0],input_arr[b][1]);
 name='A';
 wid=0;
}

int find(int i)
{
 while(parent[i])
  i=parent[i];
 return i;
}

int uni(int i,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;
}

void dis_Kruskals()
{
 glClear(GL_COLOR_BUFFER_BIT);
 Kruskals_d();
 int i=0;
 char *String="GRAPH USING KRUSKAL'S ALGORITHM";
 glRasterPos2f(6.0f,280.0f);
 for(i=0;i<strlen(String);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(int)String[i]);

 glFlush();
}

void Kruskals()
{

  glutCreateWindow("KRUSKAL");
  glutInitWindowPosition(50,50);
  glutInitWindowSize(500,500);
  glutPositionWindow(320,380);
   glutReshapeWindow(320,320);
   init();
  glutDisplayFunc(dis_Kruskals);
  glutReshapeFunc(reshape);
  glutMainLoop();
}


void Dijkstras_d()   //main program
{

int a[size][size],i,j,n,v1,v2,lcost;
int dij(int[][j],int,int,int);
printf("Enter the number of vertex : ");
//scanf("%d",&n);
n=nodes;
/*Input 0 if there is no direct edge between vertex pair*/
printf("Enter a weighted matrix(with weights) as input :\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
//printf("Enter the value of a[%d][%d] : ",i,j);
//scanf("%d",&a[i][j]);
a[i][j]=adj[i][j];
}
}
printf("The entered matrix is:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
printf("%d\t",a[i][j]);
printf("\n");
}
printf("Enter starting vertex v:");
//scanf("%d",&v1);
v1=1;
printf("Enter ending vertex v:");
v2=dln;
printf("\n-->%d<---\n",v2);
//scanf("%d",&v2);
/*Check for validity of input vertices*/
if(v1<0||v1>n-1||v2<0||v2> n)
{
//printf("!!!!!ERROR!!!!!\n");
//printf("!!!!!Invalid vertex given!!!!!");
return;
}
printf("Shortest path between v%d & v%d : ",v1,v2);
lcost=dij(a,n,v1,v2);
printf("Shortest cost between v%d & v%d : ",v1,v2);
printf("%d",lcost);
cost_d=lcost;
/*Print the shortest cost*/
}

/*The input graph,no. of vertices n,source vertex v1 and destination vertex v2 are passed as parameters*/
int dij(int a[size][size],int n,int v1,int v2)
{
    int min;
int length[size],set[size],path[size],i,j,s,z,tmp,temp[size],c=0,f=0;
s=v1;
z=v2;
//int srch_min(int[],int[],int);
for(i=0;i<n;i++)
set[i]=0;
for(i=0;i<n;i++)
{
if(a[s][i]==0)/*There is no direct edge between vertices s and i*/
{
length[i]=inf;
path[i]=0;/*Empty path*/
}
else
{
length[i]=a[s][i];
path[i]=s;/*s is immediate predecessor of i*/
}
}
set[s]=1;/*s is included in the set*/
length[s]=0;/*s is implicitly enumerated with length as 0*/
int a1,b1;
while(set[z]!=1)/*Iteration will be considered until final vertex z belongs to s*/
{
j=srch_min(length,set,n);/*Select a vertex j with minimum label such that it is not included in the set[]*/
set[j]=1;/*Vertex j is included in the set[]*/

for(i=0;i<n;i++)
{
if(set[i]!=1)
{
if(a[i][j]!=0)
{
if(length[j]+a[i][j]<length[i])/*When exsisting label is not minimum only then replacement is done*/
{
length[i]=length[j]+a[i][j];
path[i]=j;
}
}
}
}
}
j=0;
i=z;
while(i!=s)
{
tmp=path[i];
temp[j]=tmp;
i=tmp;
j++;
c++;
}

for(j=c-1;j>=0;j--)
{
     printf("v%d->",temp[j]);
     int a=temp[j];
     int b=temp[j-1];
     if(j-1<0) b=z;
                        printf("a(%d)->b(%d)",input_arr[a][0],input_arr[b][0]);
                              glColor3f(r,g,b);
                                    if(wid==1){
                                      glLineWidth(3.0f);
                                      }
                                      glBegin(GL_LINES);
                            glVertex2i(input_arr[a][0],input_arr[a][1]);
                                   glVertex2i(input_arr[b][0],input_arr[b][1]);
                                   glEnd();
                                glFlush();
             if(a1!=a){
                        name=name+a-1;
                          printf("\n abhai %c <--",name);
                          draw_nod(input_arr[a][0],input_arr[a][1]);
                          name_node(name,input_arr[a][0],input_arr[a][1]);
                          name='A';
                      }


          if(b1!=b){name=name+b-1;
                          printf("\n bbhai %c <--",name);
                          draw_nod(input_arr[b][0],input_arr[b][1]);
                          name_node(name,input_arr[b][0],input_arr[b][1]);
                          name='A';
          }
          a1=a;
          b1=b;
                        min =sqrt(pow((input_arr[b][0]-input_arr[a][0]),2)+pow((input_arr[b][1]- input_arr[a][1]),2));
                        int midx=(input_arr[a][0]+input_arr[b][0])/2;
                        int midy=(input_arr[a][1]+input_arr[b][1])/2;
                        cost_n(min,midx,midy);


if(temp[j]==z)
f=1;
}

if(f!=1){
printf("v%d",z);
printf("\n");
}

return length[z];

name='A';
wid=0;

}

int srch_min(int length[],int set[],int n)
{
int min,i,min_index;
min=99999,min_index;
for(i=1;i<n;i++)
{
if(set[i]!=1)
{
if(length[i]<min)
{
min=length[i];
min_index=i;
}
}
}
return min_index;
}



void dis_Dijkstras()
{
 glClear(GL_COLOR_BUFFER_BIT);
 Dijkstras_d();
 int i=0;
 char *String="GRAPH USING DIJKSTRA'S ALGORITHM";
 glRasterPos2f(6.0f,280.0f);
 for(i=0;i<strlen(String);i++)
 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(int)String[i]);

 glFlush();
}
void reshape_c(GLsizei WIDTH,GLsizei HEIGHT){
    glViewport(0, 0,WIDTH,HEIGHT);
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0.0f,320.0f,750.0f,0.0f);
}

void Dijkstras()
{
  glutCreateWindow("DIJKSTRAS");
  glutInitWindowPosition(50,50);
  glutInitWindowSize(500,500);
  glutPositionWindow(640,30);
   glutReshapeWindow(320,320);
   init();
  glutDisplayFunc(dis_Dijkstras);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
void grid(){
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(5,670);
glVertex2f(305,670);
glVertex2f(305,25);
glVertex2f(5,25);
glEnd();

int gx=5,gy=670;

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gx=gx+50;
glBegin(GL_LINES);
glVertex2f(gx,gy);
glVertex2f(gx,gy-645);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gx=gx+50;
glBegin(GL_LINES);
glVertex2f(gx,gy);
glVertex2f(gx,gy-645);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gx=gx+50;
glBegin(GL_LINES);
glVertex2f(gx,gy);
glVertex2f(gx,gy-645);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gx=gx+50;
glBegin(GL_LINES);
glVertex2f(gx,gy);
glVertex2f(gx,gy-645);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gx=gx+50;
glBegin(GL_LINES);
glVertex2f(gx,gy);
glVertex2f(gx,gy-645);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gx=gx+50;
glBegin(GL_LINES);
glVertex2f(gx,gy);
glVertex2f(gx,gy-645);
glEnd();

 gx=5,gy=670;

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();
glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glColor3f(0.40,0.40,0.40);
//while(gx<=270){
gy=gy-50;
glBegin(GL_LINES);
glVertex2f(gx+300,gy);
glVertex2f(gx,gy);
glEnd();

glFlush();
}


void graph()
{	glClearColor(0.0f,0.0f,0.0f,1.0f);
    glColor3f(0.0,0.0,0.0);                                        //horizontal
	glBegin(GL_LINES);
    glVertex2i(5,670);
    glVertex2i(305,670);
	glEnd();
	//vertical
	glBegin(GL_LINES);
    glVertex2i(5,25);
    glVertex2i(5,680);
	glEnd();
	    char *String ="0";
	glRasterPos2f(6.0f,685.0f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
       //
	glBegin(GL_LINES);
    glVertex2i(55,660);
    glVertex2i(55,680);
	glEnd();
	   char *String5 ="5";
	   char *String1 ="1";
	   char *String2 ="2";
	   char *String3 ="3";
	glRasterPos2f(56.0f,685.0f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String5[0]);

	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);

	  //
	glBegin(GL_LINES);
    glVertex2i(105,660);
    glVertex2i(105,680);
	glEnd();
	glRasterPos2f(106.0f,685.0f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String1[0]);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
    //
	glBegin(GL_LINES);
    glVertex2i(155,660);
    glVertex2i(155,680);
	glEnd();
		glRasterPos2f(156.0f,685.0f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String1[0]);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String5[0]);
	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
    //
	glBegin(GL_LINES);
    glVertex2i(205,660);
    glVertex2i(205,680);
	glEnd();
	glRasterPos2f(206.0f,685.0f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String2[0]);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
    //
    glBegin(GL_LINES);
    glVertex2i(255,660);
    glVertex2i(255,680);
	glEnd();
	 glRasterPos2f(256.0f,685.0f);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String2[0]);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String5[0]);
	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
    //
	glBegin(GL_LINES);
    glVertex2i(305,660);
    glVertex2i(305,680);
	glEnd();
		glRasterPos2f(306.0f,685.0f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String3[0]);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)String[0]);
    //
	glFlush();

    glBegin(GL_LINES);
    glVertex2i(100,700);
    glVertex2i(180,700);
	glVertex2i(180,700);
    glVertex2i(155,710);
	glVertex2i(180,700);
    glVertex2i(155,690);
	glEnd();
	int i;
             char *String78="ALGORITHMS";
                                   glRasterPos2f(140,720);
	                               for(i=0;i<strlen(String78);i++)
                                   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(int)String78[i]);
                                   glFlush();


}
void rect(int x,int y,int l)
{
glColor3f(r,g,b);
glBegin(GL_POLYGON);
glVertex2i(x,y);
glVertex2i(x+40,y);
glVertex2i(x+40,y-l);
glVertex2i(x,y-l);
glEnd();
glFlush();
}

void bar()
{
    /*if(cost_d>300 || cost_k>300 || cost_p>300)
    {
      //  cost_d=cost_d-200;
        cost_p=cost_p-200;
        //cost_k-=100;
    }*/
    printf("\n cost %d",cost_d);
    //prims
    r=0.0f; g=1.0f; b=0.0f;
    rect(50,670,cost_p);
    //kruskal
    r=0.0f; g=0.50f; b=0.50f;
    rect(100,670,cost_k);
    //dijks
    r=0.70f; g=0.30f; b=0.50f;
    rect(150,670,cost_d);

    r=0.0f; g=1.0f; b=1.0f;
    glFlush();
    }
/*void reshape_c(GLsizei WIDTH,GLsizei HEIGHT){
    glViewport(0, 0,WIDTH,HEIGHT);
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0.0f,320.0f,520.0f,0.0f);
}*/

void dis_compare(){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  wid=1;
  r=0.0f;
  g=0.0f;
  b=1.0f;
  Prims_d();
wid=1;
  glLineWidth(5);
  r=1.0f;
  g=0.0f;
  b=0.0f;
  Kruskals_d();
wid=1;
  r=0.0f;
  g=1.0f;
  b=0.0f;
  Dijkstras_d();

glFlush();
}
void COMP1(){
	glutCreateWindow("COMPARE");
    glutInitWindowSize(320,320);
    glutReshapeWindow(320,500);
    glutInitWindowPosition(450,50);
	glutPositionWindow(960,30);
	init();
    glutDisplayFunc(dis_compare);
    glutReshapeFunc(reshape_c);
    glutMainLoop();
}

void dis_comp(){
  glClear(GL_COLOR_BUFFER_BIT);
  graph();
  grid();
  bar();
glFlush();
}

void COMP(){
	glutCreateWindow("COMP");
    glutInitWindowSize(320,320);
    glutReshapeWindow(320,420);
    glutInitWindowPosition(450,50);
	glutPositionWindow(960,30);
	init();
    glutDisplayFunc(dis_comp);
    glutReshapeFunc(reshape_c);
    glutMainLoop();
}

void menu(int num)
{
if(num==4)
{
 printf("clear");
 glClearColor(1.0f,1.0f,1.0f,0.0f);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0f,0.0f,0.0f);
       glBegin(GL_POINTS);
        for(int i=1;i<=nodes;i++)
        glVertex2i(input_arr[i][0],input_arr[i][1]);
        glRasterPos2i(x,y+1);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,(char)str);
        str++;
        glEnd();
        glFlush();
       flag=1;
       i=1;
        j=2;
glutPostRedisplay();
}

else if(num == 1)
  {
  Prims();
  }
else if(num ==2)
  {
  Kruskals();
  }
else if(num==3)
  {
  Dijkstras();
  }
else if(num==31)
{
    dln = nodes;
    printf("-->%d<---",dln);
Dijkstras();
}
else if(num==32)
{
    dln=nodes-1;
    printf("-->%d<---",dln);
Dijkstras();
}
else if(num==33)
{
    dln=nodes/2;
    printf("-->%d<---",dln);
Dijkstras();
}
else if(num==5)
{
     COMP1();
}
else if(num==6)

{
      COMP();
}

else
{
 exit(0);
}
}

void createMenu(void){
      submenu_id=glutCreateMenu(menu);
  //   glutAddMenuEntry("LAST NODE",31);
    glutAddMenuEntry("SECOND LAST NODE",32);
    glutAddMenuEntry("MIDDLE NODE",33);

     submenu_id1=glutCreateMenu(menu);
     glutAddMenuEntry("Graphical",5);
     glutAddMenuEntry("Statistical",6);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("CLEAR",4);
    glutAddMenuEntry("PRIMS", 1);
    glutAddMenuEntry("KRUSKALS", 2);
    glutAddSubMenu("DIJKSTRAS", submenu_id);
    glutAddSubMenu("COMPARISION", submenu_id1);

    glutAddMenuEntry("QUIT" , 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc, char **argv)
{

printf ("Enter the number of nodes: ");
  scanf("%d",&nodes);
  dln=nodes;
  for(int f=0;f<nodes;f++)
        {
            for(int d=0;d<nodes;d++){
            adj[f][d]=0;
            }
}
  input_left=1;
  glutInit(&argc,argv);
  glutCreateWindow("INPUT");
  glutInitWindowPosition(50,50);
  glutInitWindowSize(500,500);
   glutReshapeWindow(320,320);
   glutPositionWindow(15,30);
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}

