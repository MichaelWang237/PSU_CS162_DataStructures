
// GRAPH CREATOR
// Michael Wang
// 6/9/2021

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


struct vertex{
    char* name =(char*)"\0";
};

struct edge{
    int weight = 0;
    char* start;
    char* end;
};
struct node{
    vertex* dataV= NULL;
    edge* dataE= NULL;
    node* next = NULL;
};

//Function Prototypes--------------------------

void addVertex(char* name, node* V);
void addEdge(char* startName, char* endName, int weight, node* E, node* V);
bool removeVertex(char* name, node* V, node* E);
bool removeEdge(char* startName, char* endName, node* E, node* V);
int shortestPath(vertex* start, vertex* end, node* V, edge* E);
char* getName(vertex* v, node* V);
void listVertices(node*V);
void listEdges(node* E);
void adjTable(node* E, node* V);
int findLength(int i, node* n);
bool findEdge(char* startName, char* endName, node* E);


int main(){

    //NODES V and E act as "head" nodes for the linked list that stores the vertices and edges, respectively.
    node* V = new node();
    node* E = new node();
    int i = 0;
    int a = 0;

    //Input loop
    while (true){
        if(a == 0){
            cout << "Welcome to my (incomplete) graph creator -- there's no function to calculate the shortest path." << endl;
            a=1;
        }
        cout << "Type [adj] to print an adjacency table, [av] to add a vertex, [ae] to add an edge, [rv] to remove a vertex, and [re] to remove an edge." << endl; 
        char* input = new char[100];
        cin.clear();
        cin.getline(input, 100);

        //Printing adj table requires no further input.
        if(strcmp (input, "adj")== 0 && i == 0){
            cout << "you need to have at least 1 vertex to print an adj table." << endl;
        }
        else if(strcmp (input, "adj")== 0 && i == 1 ){
            cout << "Note: true/false won't show up unless there is at least one edge" << endl;
            adjTable(E, V);
        }
        //Adding a vector: takes in the vector name as input. Limit of 1 character is mostly for the Adjacency table
        else if(strcmp (input, "av")== 0){
            char* inpt = new char;
            cout << "Enter a 1-character long name for the vertex:" << endl;
            cin.getline(inpt, 2);
            addVertex(inpt, V);
            i= 1;    
        }
        //Adding an edge: takes in the weight, starting point and destination of an edge as input.
        else if(strcmp (input, "ae")== 0){
            char* start = new char[1];
            char* end = new char[1];
            int w = 0;
            cout << "Enter the starting vertex for this edge" << endl;
            cin.getline(start, 2);
            cout << "Enter the destination for this edge" << endl;
            cin.getline(end, 2);
                cout << "Enter the weight for this edge. Must be an integer greater than 0" << endl;
                cin >> w;
            addEdge(start, end, w, E, V);
        }
        //Removing a vertice: user enters name of vertex to be deleted.
        else if(strcmp (input, "rv")== 0){
            char* name = new char[1];
            cout << "Enter the name of the vertex you want to delete" << endl;
            cin.getline(name, 2);
            if(removeVertex(name, V, E) == true){
                V = V->next;
            };
        }
        //Removing an edge: user enters starting and end points of edge to be deleted.
        else if(strcmp (input, "re")== 0){
            char* start = new char[1];
            char* end = new char[1];
            cout << "Enter the starting vertex for the edge you'd like to delete" << endl;
            cin.getline(start, 2);
            cout << "Enter the destination for this edge you'd like to delete" << endl;
            cin.getline(end, 2);
            removeEdge(start,end,E,V);

        }
        else{
            cout << "Please enter a valid command" << endl;
        }
    }
}

//Finds length of a linked list. This is used to help draw the adjacency table.
int findLength(int i, node* n){
    while(n != NULL){
        if(n->next == NULL){
            break;
        }
        if(n->next != NULL){
        n = n->next;
        }
        
        i++;
    }
    return i;
}
/*if(((char*)tempPos->dataV->name))&& (char*)temp2->dataV->name, E) ){
                cout << " t" << flush;
                
            }
            else{
                cout << tempPos->dataV->name << temp2->dataV->name << findEdge((char*)tempPos->dataV->name, (char*)temp2->dataV->name, E) << E->dataE->start << E->dataE->end << flush;
                cout << "f" << flush;
            }*/

//Draws adjacency table.
void adjTable(node* E, node* V){
    cout <<"Building Table..." << endl;
    if(findLength(1,V) == 1){
        cout << "There is currently 1 vertex" <<endl;
    }
    else{
        cout <<"There are currently " << findLength(1, V)<< " vertices" << endl;
    }
    node* temp = V;
    node* temp2 = V;
    cout << " " << flush;
    //Puts in X-axis vertex names
    for(int i = 0; i < findLength(1, V); i++){
        if(strcmp(temp->dataV->name, (char*)"\n") == 0){
            cout<< "Null character" << flush;
            node* p = temp;
            temp = temp->next;
            delete p;
        }
        cout << " " << temp->dataV->name << flush;
        temp = temp->next;
    }
    for(int i = 0; i < findLength(1, V); i++){// "Row number" of adj table
        if(strcmp(temp2->dataV->name, (char*)"\n") == 0){
            cout<< "Null character" << flush;
            node* p = temp2;
            temp2 = temp2->next;
            delete p;
        }
        cout << endl;
        cout << temp2->dataV->name << flush; //Prints y-axis vertex names
        node* tempPos = V;
        for(int i = 0; i < findLength(1, V); i++){// "Column number"
            node* temp1 = E;
            while(temp1->dataE != NULL){  
                if(strcmp((char*)temp1->dataE->start, (char*)tempPos->dataV->name) == 0 && strcmp((char*)temp1->dataE->end, (char*)temp2->dataV->name) == 0){
                    cout << " t" << flush;
                    break;
                }  
                if(temp1->next != NULL){
                    temp1 = temp1->next;
                }
                else if(temp1->next == NULL || temp1 == NULL){
                
                    cout << " f" << flush;
                    break;
                }
            }
            tempPos = tempPos->next;

        }
        temp2 = temp2->next;
    }
    cout << endl;
    
}   

//Add a new vertex with a given name.
void addVertex(char* name, node* V){
    int i = 0;
    node* a = new node(); 
    vertex* v = new vertex();
    node* t = V;
    v->name = name;
    a->dataV = v; 
    //If the list is empty...
    if(V->dataV == NULL){
        cout << "Adding first node" << endl;
        V->dataV = v;
        i = 1;
    }
    //If the list has exactly 1 element...
    if(V->dataV != NULL && V->next == NULL && i == 0){
        V->next = a;
        i = 1;
    }
    else if(i == 0){
        while(true){
            if(t->next == NULL){
               break; 
            }
            t = t->next;
        }
            t->next = a;         
    }
    cout << "Added a vertex called " << a->dataV->name << endl;
}
// Add a new edge between 2 vertices
void addEdge(char* startName, char* endName, int weight, node* E, node* V){
    int i = 0;
    node* b = new node();
    edge* e = new edge();
    node* a = E;
    e->start = startName;
    e->end= endName;
    e->weight = weight;
    b->dataE = e; 
    //If the list is empty,
    if(E->dataE == NULL){

        E->dataE = e;
        i = 1;
    }
    //If there is exactly one member in the list...
    else if(E->dataE != NULL && E->next == NULL && i == 0){

        E->next = b;
        i = 1;
    }
    else if(i == 0){
        while(true){
            if(a->next == NULL){
                break;
            }
            a = a->next;   
        }
        a->next = b;
    }
    cout << "Added edge that connects vertex " << e->start << " to vertex " << e->end << " with weight " << weight << endl;
}

//Lists the vertices in the graph -- USED FOR TESTING PURPOSES ONLY
void listVertices(node*V){
    cout << endl;
    node* temp = V;
    int i = 1;
    while(temp->dataV != NULL){
        cout << "vertex " << i << " is " << temp->dataV->name << endl;
        temp = temp->next;
        i++;
    }
}
//Lists the edges in the graph -- USED FOR TESTING PURPOSES ONLY
void listEdges(node* E){
    cout << endl;
    node* temp = E;
    int i = 1;
    while(temp->dataE != NULL){
        edge* e = temp->dataE;
        cout << "edge " << i << " starts at " << e->start << " and ends at " << e->end << endl;
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
        i++;
    }
}

//Removes a vertex and its associated edges
bool removeVertex(char* name1, node* V, node* E){
    int i = 0;
    node* tempPrev = NULL;
    node* temp = new node();
    temp = V;

    while(true){
        //If temp is the node we're looking for...
        if(strcmp(temp->dataV->name,name1) == 0){
            cout << "Vertex found. Removing..." << endl;
            node* tempE = E;
            //Cycle through list of edges to see if one is connected to the vertex that is about to be deleted. If there's a connected edge, delete it.
            while(tempE != NULL){
                if(strcmp(tempE->dataE->start, temp->dataV->name)==0){
                    cout << "Deleting an edge that starts from here "<< endl;
                    removeEdge(temp->dataV->name, (char*)"\0", E, V);
                }
                else if(strcmp(tempE->dataE->end, temp->dataV->name)==0){
                    cout << "Deleting an edge that currently points at points here" << endl;
                    removeEdge((char*)"\0", temp->dataV->name, E, V);
                }
                tempE = tempE->next;
            }
            cout << " out of delete" << endl;
            
            //Setting affairs in order with regards to linked list of vertices prior to deletion:
            //----------------------------------------------------
            //If this is a middle node in the list:
            if(tempPrev != NULL && temp->next != NULL){
                cout << "middle" << endl;
                tempPrev->next = temp->next;
            }
            //If the first node in the list is the one to be deleted... 
            else if(tempPrev == NULL){
                cout << "first" << endl;
                cout << "changing V from" << V->dataV->name << "to" << flush;
                V = temp->next;
                cout << V->dataV->name << endl;
                return true;
            }
            //If the node to be deleted is the last one in the list...
            else{
                cout << "last" << endl;
               tempPrev->next = NULL; 
            }
            //--------------------------------------------------
            cout << "Deleting " << name1 << endl;
            temp->dataV->name = (char*)"\n";
            delete temp;
            cout << "Deleted" << endl;
            i = 1;
            break; //Break after deletion
        }
        else if(i == 0){
            if(temp->next == NULL){
                cout << "There is no vertex named " << name1 << endl;
                break;//...Or when there are no more nodes in the list of vertices.
            }
        }
        tempPrev = temp;
        temp = temp->next;
    }
    return false;
}
//Used to find an edge with the given starting and endpoints.
bool findEdge(char* startName, char* endName, node* E){
   
    node* temp = E;
    
    bool TF = false;
    
    while(temp->dataE != NULL){  
        if(temp->dataE->start == startName && temp->dataE->end == endName){
            
            TF = true;
            
            break;
        }
        if(temp->next != NULL){

            temp = temp->next;
        }
        else if(temp->next == NULL){
            break;
        }
    }

    return TF;
}
//Removes the edge that starts at a certain vertex and ends at another.
bool removeEdge(char* startName, char* endName, node* E, node* V){
    int i = 0;
    int t = 0;
    node* tempPrev = NULL;
    node* temp = E;

    while(temp->dataE != NULL){
        if((strcmp(temp->dataE->start, startName)== 0 || strcmp(startName, (char*)"\0") == 0) && (strcmp(temp->dataE->end, endName)==0 || strcmp(endName , (char*)"\0")== 0)){
            cout << "Edge found!" << endl;
            
            //If this is a middle node:
            if(tempPrev != NULL && temp->next != NULL){
                cout << "One of the middle nodes will be deleted" << endl;
                tempPrev->next = temp->next;
            }
            //If the first node in the list is the one to be deleted... 
            else if(tempPrev == NULL && temp->next == NULL && temp!= NULL){
                E = E->next;
                t = 2;
            }
            //If the node to be deleted is the last one in the list...
            else{
               cout << "Last node will be deleted" << endl;
               tempPrev->next = NULL; 
               cout << "still here" << endl;
            }
            cout << "Deleting edge that starts at " << temp->dataE->start << " and ends at " << temp->dataE->end << endl;
            delete temp;
            i = 1;
            break;
        }
        else if(i == 0){
            if(temp->next == NULL){
            cout << "There is no edge that starts at " << startName << " and ends at " << endName << endl;
            break;
            }
        }
        tempPrev = temp;
        temp = temp->next;
    }
    if(t = 2){
        return true;
    }
    else{
        return false;
    }
}
//didn't bother starting.
int shortestPath(vertex* start, vertex* end, node* V, edge* E){
    int distance = 0;

    return distance;
}