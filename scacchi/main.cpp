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
        bool moves[8][8];
        int pos[2];
        bool is_taken;
        bool checked = false;

    piece(int cpos[2], int id, char color='w'){

        int x = cpos[0], y = cpos[1];

        switch (id)
        {
        
        case 1:         //PAWN
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(color == 'b'){
                        if(x == i && (y+1 == j || y+2 == j) ){
                            moves[i][j] = true;
                        }
                    }else{
                        if(x == i && (y-1 == j || y-2 == j) ){
                            moves[i][j] = true;
                        }
                    }
                }
            }
            break;
        
        case 2:         //BISHOP
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if( ((i-x) == (j-y)) || ((i-x) + (j+y) == x+y)){
                        moves[i][j] = true;
                    }
                }
            }
            break;
        
        case 3:         //ROOK
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(x == i || y == j ){
                        moves[i][j] = true;
                    }
                }
            }
            break;
        
        case 4:         //HORSE
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(i<=x+2 && j<=y+2 & i>=x-2 && j>=y-2){
                        moves[i][j] = true;
                    }
                }
            }

            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(x == i || y == j ){
                        moves[i][j] = false;
                    }
                    if( ((i-x) == (j-y)) || ((i-x) + (j+y) == x+y)){
                        moves[i][j] = false;
                    }
                }
            }
            break;

        case 5:         //KING
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(i<=x+1 && j<=y+1 & i>=x-1 && j>=y-1){
                        moves[i][j] = true;
                    }
                }
            }
            break;

        case 6:         //QUEEN
            for(int i=0; i<8; i++){
                for (int j = 0; j<8; j++)
                {
                    if(x == i || y == j ){
                        moves[i][j] = true;
                    }
                    if( ((i-x) == (j-y)) || ((i-x) + (j+y) == x+y)){
                        moves[i][j] = true;
                    }
                }
            }
            break;
        
        default:
            break;
        }

    }
};

void prtMoves(piece p){
    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            if(p.moves[j][i]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
}

class board{
    public:
        piece current[8][8];

};

void init_board(board b){
    b.current[0][0].
}

int main(){

    int pos[2] = {4,4};
    piece pedone(pos,0);
    prtMoves(pedone);

}