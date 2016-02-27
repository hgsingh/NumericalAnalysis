#include "fractals.h"

void drawTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clears the color and depth buffers
    glColor3f(1.0f, 1.0f, 1.0f); //set initial color, color of the points are changed later    
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);//orthogonalization, usually used for 3d stuff
    
    vertex point_a; //not going to use dynamic allocation because the heap space is already being used a lot by the gl
    vertex point_b;
    vertex point_c;

    point_a.x = -1.0f;
    point_a.y = 1.0f;
    point_a.z = 0.0f;

    point_b.x = 1.0f;
    point_b.y = 1.0f;
    point_b.z = 0.0f;

    point_c.x = 0.0f;
    point_c.y = -1.0f;
    point_c.z = 0.0f;

        glBegin(GL_TRIANGLES); //making the initial triangle
            glVertex3f(point_a.x, point_a.y, point_a.z);
            glVertex3f(point_b.x, point_b.y, point_b.z); //setting the vertices
            glVertex3f(point_c.x, point_c.y, point_c.z);
        glEnd();  

    glColor3ub(0, 0, 255); //setting the color to blue

    vertex initial_point;
    initial_point.x = 0.0f;
    initial_point.y = 0.3f;
    initial_point.z = 0.0f;
   

    glBegin(GL_POINTS);
        glColor3ub(0, 0, 255);
        glVertex3f(initial_point.x, initial_point.y, initial_point.z); //"randomly selecting" the first point
        recurse_triangles(&initial_point, point_a, point_b, point_c, 0);         
    glEnd();    
    
    glFlush();
    std::cout<<"I was called"<<std::endl;
}

int recurse_triangles(vertex* point, const vertex &a, const vertex &b, const vertex &c, int iteration)
{
    int x = rand() % 3 + 1; //returns 1 to 3
   
    
    if(iteration == 100000)
    {
        std::cout<<iteration<<std::endl;
        return iteration;
    }
    vertex new_point;
    if(x == 1)
    {    
        half_way(point, a, new_point);
        glVertex3f(new_point.x, new_point.y, new_point.z); 
        return recurse_triangles(&new_point, a, b, c, ++iteration);        
    }
    if(x == 2)
    {
        half_way(point, b, new_point);
        glVertex3f(new_point.x, new_point.y, new_point.z); 
        return recurse_triangles(&new_point, a, b, c, ++iteration);  
    }
    if(x == 3)
    {
        half_way(point, c, new_point);
        glVertex3f(new_point.x, new_point.y, new_point.z); 
        return recurse_triangles(&new_point, a, b, c, ++iteration);  
    }
    return 0;
}

int half_way(vertex* point, const vertex &a, vertex &new_point)
{
    if(point != NULL)
    {
        new_point.x = ((point->x)+(a.x))/2;
        new_point.y = ((point->y)+(a.y))/2;
        new_point.z = ((point->z)+(a.z))/2;
        return 1;
    }
    std::cout<<"point is null dawg"<<std::endl;
    return 0;
}

void init_rendering()
{

    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Serpenski Gasket");
    init_rendering();
    glutDisplayFunc(drawTriangle);
    glutMainLoop();
    return 0;
}
