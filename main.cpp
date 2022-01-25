#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

using namespace std;


//for changing values in 2D array
void myFunc(double *a,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            *(a+ i*rows + j)+=10.0;
        }
    }
}

void show_mtrx(int * matrix, int & n,int & steps, int & row, int & column)
{
    for(int stp_c{0}; stp_c < steps; ++stp_c)  //iterating on steps
    {            

            cout << *(matrix+ row*n + column) << " ";
                
            row--;
            column++;
    }
}



int main(int argc, const char** argv)
{
    vector<int> temp_cont;

    temp_cont.push_back(1);
    temp_cont.push_back(2);

    for(auto & el : temp_cont)
    {
       // cout << el << "\n";
    }


    for(int i{0}; i < argc; ++i)
    {
       cout << *(argv + i) << endl;
    }


    
    int n{0};
     cout << "enter N: ";
     cin >> n;

    int matrix[n][n];

    short counter{1};
    for(int i{0}; i < n; ++i)
    {
        for(int j{0}; j < n; ++j)
        {
            matrix[i][j] = counter;
            counter++;
        }
    }



    ////////////////////////////////////////////////

        int row{1};
        int column{0};
        int steps{2};
        int longest_diag = n;

   
        while(steps <= longest_diag) //iterates on left side from longest diagonal
        {
            // for(int stp_c{0}; stp_c < steps; ++stp_c)  //iterating on steps
            // {
            //     cout << matrix[row][column] << " ";
                
            //     row--;
            //     column++;
            // }

            show_mtrx(*matrix,n,steps, row, column);

            
            steps++;
            row = steps - 1;
            column = 0;
        }      
    


        row = n-1;
        column = 1;
        steps = n - 1;

        while(steps >= 2) //iterates on right side from longest diagonal
        {  

            // for(int stp_c{0}; stp_c < steps; ++stp_c)  //iterating on steps
            // {
            //     cout << matrix[row][column] << " ";
                
            //     row--;
            //     column++;
            // }

            show_mtrx(*matrix,n,steps, row, column);
            
            steps--;
            row = n-1;
            column = n - steps ;
        }


        ///////////////////////////


    return 0;
}