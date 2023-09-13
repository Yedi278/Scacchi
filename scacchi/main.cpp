#include <iostream>
using namespace std;

// pawn     0
// bishop   1
// rook     2
// horse    3
// king     4
//  queen   5

// pisello
class piece{

    public:
        int id = 0;
        bool avb_moves[8][8];
        int pos[2];
        bool is_taken = true;
    piece(int cpos[2]){

        switch (id)
        {
        
        case 0:         //PAWN
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(cpos[0] == i && (cpos[1]+1 == j || cpos[1]+2 == j) ){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;
        
        case 1:         //BISHOP
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if( (i-cpos[0]) == (j-cpos[1])){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;
        
        case 2:         //ROOK
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(cpos[0] == i || cpos[1] == j ){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;
        
        case 3:         //HORSE
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {   
                    int x = i-cpos[0];
                    int y = j-cpos[1];

                    if(((x <= 2) || (y <= 2)) && (x != y) && (i!=cpos[0] || j!= cpos[1])){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;

        case 4:         //KING
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    // if()
                }
            }
            break;

        case 5:         //QUEEN
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    
                }
            }
            break;
        
        default:
            cout << "Errore nella creazione del pezzo";
            break;
        }
    }
};



class board{
    public:
        piece occupied[8][8];

};

int main(){
    
}