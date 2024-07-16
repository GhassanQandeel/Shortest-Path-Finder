

/*GHASSAN QANDEEL
1212397
SECTION 3*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_CITIES 15
#define MAX 99999
//define 2-Dim graph
int cities_graph[NUM_CITIES][NUM_CITIES];
//  made the cities has numbers from 0 to 14
char city_name_initialize[NUM_CITIES][100];
//define array for print all paths on file
char data_to_file[100][1000];
//index of data_to_file
int index_data=0;

//to return index of cities
int Cities_Index( char city_name[]);
//Dijkstra function
void Dijkstra(int start_vertex, int end_vertex);
//BFS function
void BFS(int start_vertex, int end_vertex);
//function to display menu and return any number user choice
int DisplayMenu();
//function to save data from file to graph
void Load_info();
//function to save data from  data_to_file array to file
void store_info();


int main()
{
//switch to know any choice user want
    int sw;
    // string to save first city from user
    char firstcity[1000];
// string to save second  city from user
    char secondcity[1000];

    printf("welcome,please choose what you want to do\n\n");
    sw=DisplayMenu();

    while(sw!=0)
    {
        if(sw==1)//load data from file and saved in graph
        {
            printf("your choice is : %d\n",sw);
            Load_info();
            sw=DisplayMenu();
        }
        else if(sw==2)//to insert source city
        {
            printf("your choice is : %d\n",sw);
            printf("the source city is :");
            scanf("%s",firstcity);
            sw=DisplayMenu();
        }
        else if(sw==3)//to insert  destination  city and show result of paths
        {
            printf("your choice is : %d \n",sw);

            printf("the destination city is :");
            scanf("%s",secondcity);

            printf("Shortest path using Dijkstra's algorithm:\n");
            Dijkstra(Cities_Index(firstcity),Cities_Index(secondcity) );

            printf("\nShortest path using BFS algorithm:\n");
            BFS(Cities_Index(firstcity),Cities_Index(secondcity) );
            sw=DisplayMenu();
        }
        else if(sw==4)//save data in
        {
            printf("your choice is : %d \n",sw);
            store_info();
            printf("all paths save in file .\n\n");
            sw=0;
        }

    }

    return 0;
}
void Load_info()
{
    FILE* file = fopen("Cities.txt", "r");

    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return -1;
    }

    char firstcity[1000];
    char secondcity[1000];
    char distance[1000];
    int dist;
//read from file and store in graph
    while (fscanf(file, "%s %s %s", firstcity, secondcity, distance) != EOF)
    {
        dist = atoi(distance);
        cities_graph[Cities_Index(firstcity)][Cities_Index(secondcity)] = dist;
    }


    fclose(file);

}

int Cities_Index( char city_name[])
{

    strcpy(city_name_initialize[0], "Akka");
    strcpy(city_name_initialize[1], "Haifa");
    strcpy(city_name_initialize[2], "Nazareth");
    strcpy(city_name_initialize[3], "Jenin");
    strcpy(city_name_initialize[4], "Bethlehem");
    strcpy(city_name_initialize[5], "Hebron");
    strcpy(city_name_initialize[6], "Jerusalem");
    strcpy(city_name_initialize[7], "Jaffa");
    strcpy(city_name_initialize[8], "Jericho");
    strcpy(city_name_initialize[9], "Tulkarem");
    strcpy(city_name_initialize[10], "Qalqilya");
    strcpy(city_name_initialize[11], "Tubas");
    strcpy(city_name_initialize[12], "Nablus");
    strcpy(city_name_initialize[13], "Ramallah");
    strcpy(city_name_initialize[14], "Salfit");

    for(int i = 0; i < NUM_CITIES; i++)
        if (strcasecmp(city_name, city_name_initialize[i]) == 0)
            return i;

    return -1;  // City not found
}

void Dijkstra(int start_vertex, int end_vertex)
{
    int distances[NUM_CITIES];
    int visited[NUM_CITIES];
    int path[NUM_CITIES];

    for(int i = 0; i < NUM_CITIES; i++)
    {
        distances[i] = 99999;
        visited[i] = 0;
        path[i] = -1;
    }

    distances[start_vertex] = 0;

    for(int count = 0; count < NUM_CITIES - 1; count++)
    {
        int min_distance = 99999;
        int min_index = -1;

        // Find the vertex with the minimum distance
        for(int v = 0; v < NUM_CITIES; v++)
        {
            if (!visited[v] && distances[v] <= min_distance)
            {
                min_distance = distances[v];
                min_index = v;
            }
        }

        if (min_index == -1)
            break;

        visited[min_index] = 1;

        for(int v = 0; v < NUM_CITIES; v++)
        {
            if (!visited[v] && cities_graph[min_index][v] && distances[min_index] != 99999 &&
                    distances[min_index] + cities_graph[min_index][v] < distances[v])
            {
                distances[v] = distances[min_index] + cities_graph[min_index][v];
                path[v] = min_index;
            }
        }
    }

    // Print the shortest path
    int current_vertex = end_vertex;
    if (path[current_vertex] == -1)
    {
        printf("No path found.\n");
        return;
    }

    while (current_vertex != -1)
    {
        printf("%s <- ", city_name_initialize[current_vertex]);
        strcat(city_name_initialize[current_vertex]," <- ");
        strcat(data_to_file[index_data],city_name_initialize[current_vertex]);

        current_vertex = path[current_vertex];
    }

    printf("Distance: %dkm\n", distances[end_vertex]);
    char int_str[20];
    sprintf(int_str, "%d",distances[end_vertex] );
    strcat(data_to_file[index_data],int_str);
    strcat(data_to_file[index_data],"km");
    index_data++;

}

void BFS(int start_vertex, int end_vertex)
{
    int visited[NUM_CITIES];
    int path[NUM_CITIES];

    for(int i = 0; i < NUM_CITIES; i++)
    {
        visited[i] = 0;
        path[i] = -1;
    }

    visited[start_vertex] = 1;

    int queue[NUM_CITIES];
    int front = 0;
    int rear = 0;
    queue[rear++] = start_vertex;

    while (front != rear)
    {
        int current_vertex = queue[front++];
        if (current_vertex == end_vertex)
            break;

        for(int v = 0; v < NUM_CITIES; v++)
        {
            if (!visited[v] && cities_graph[current_vertex][v])
            {
                visited[v] = 1;
                path[v] = current_vertex;
                queue[rear++] = v;
            }
        }
    }

    // Print the shortest path
    int current_vertex = end_vertex;
    if (path[current_vertex] == -1)
    {
        printf("No path found.\n");
        return;
    }

    while (current_vertex != -1)
    {
        printf("%s <- ", city_name_initialize[current_vertex]);
        strcat(city_name_initialize[current_vertex]," <- ");
        strcat(data_to_file[index_data],city_name_initialize[current_vertex]);
        current_vertex = path[current_vertex];

    }

    printf("Distance: %dkm\n\n", rear - 1);
    char int_str[20];
    sprintf(int_str, "%d", (rear - 1));
    strcat(data_to_file[index_data],int_str);
    strcat(data_to_file[index_data],"km");

    index_data++;

}



int DisplayMenu()
{
    int sw;

    printf("1-load info from file \n");
    printf("2-Enter source city \n");
    printf("3-Enter destination city \n");
    printf("4-Exit \n");
    scanf("%d",&sw);

    return sw;
}
void store_info()
{
    FILE* wfile = fopen("shortest_distance.txt", "w");
    if (wfile == NULL)
    {
        printf("Failed to open the file.\n");
        return -1;
    }

    for(int i=0; i<strlen(data_to_file); i++)
    {
        for(int j=0; j<strlen(data_to_file[i]); j++)
            fprintf(wfile,"%c",data_to_file[i][j]);
        fprintf(wfile,"\n");
    }

    fclose(wfile);
}
