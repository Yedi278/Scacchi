#include <iostream>
using namespace std;

// pawn     0
// bishop   1
// rook     2
// horse    3
// king     4
//  queen   5

//pisello odoroso

class piece{

    public:
        int id = 0;
        char color; 
        bool avb_moves[8][8];
        int pos[2];
        bool is_taken;

    piece(int cpos[2], int id, char color){

        int x = cpos[0], y = cpos[1];

        switch (id)
        {
        
        case 0:         //PAWN
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(x == i && (y+1 == j || y+2 == j) ){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;
        
        case 1:         //BISHOP
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if( ((i-x) == (j-y)) || ((i-x) + (j+y) == x+y)){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;
        
        case 2:         //ROOK
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(x == i || y == j ){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;
        
        case 3:         //HORSE
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(i<=x+2 && j<=y+2 & i>=x-2 && j>=y-2){
                        avb_moves[i][j] = true;
                    }
                }
            }

            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(x == i || y == j ){
                        avb_moves[i][j] = false;
                    }
                    if( ((i-x) == (j-y)) || ((i-x) + (j+y) == x+y)){
                        avb_moves[i][j] = false;
                    }
                }
            }
            break;

        case 4:         //KING
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(i<=x+1 && j<=y+1 & i>=x-1 && j>=y-1){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;

        case 5:         //QUEEN
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(x == i || y == j ){
                        avb_moves[i][j] = true;
                    }
                    if( ((i-x) == (j-y)) || ((i-x) + (j+y) == x+y)){
                        avb_moves[i][j] = true;
                    }
                }
            }
            break;
        
        default:
            cout << "Errore nella creazione del pezzo";
            break;
        }

        if(color == 'b'){
            for(int i=0;i<8; i++){
                for(int j=0; j<8; j++){
                    bool tmp = avb_moves[i][j];
                    avb_moves[i][j] = avb_moves[8-i][j];
                    avb_moves[8-i][j] = tmp;
                }
            }
        } 

    }
};

void prtMoves(piece p){
    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            if(p.avb_moves[j][i]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
}

class board{
    public:
        piece occupied[8][8];

};

int main(){

    int pos[2]= {4,4};
    piece pedone(pos,0,'b');
    prtMoves(pedone);

}