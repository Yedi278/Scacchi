#include <iostream>
using namespace std;

//pisello odoroso
// P , B , R , H , K , Q

class piece{

    public:
        int     id=0;
        char    color; 
        bool    moves[8][8];
        int     pos[2];
        bool    is_taken;
        bool    checked     = false;
        
        piece(){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    moves[i][j]=false;
                }
            }
        }


        void mv(int id1=0, char color1='w'){
            
            int x = pos[0], y = pos[1];
            // cout<<"pos:"<<pos[0]<<" pos 2: "<<pos[1];
            // cout<<endl;
            id = id1;
            color = color1;
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
        void init_board();
};

void board::init_board(){

    for(int i=0;i<7;i++){       //Set empty table, all id=0
        for (int j = 0; j < 8; j++)
        {
            
            current[i][j].pos[0] = i;
            current[i][j].pos[1] = j;

        } 
    }

    for(int i=0;i<8;i++){   //PAWNS

        current[1][i].mv(1,'b');
        
        current[6][i].mv(1,'w');

    }
    //Rooks
    current[0][0].mv(3,'b');
    current[0][7].mv(3,'b');
    current[7][0].mv(3,'b');
    current[7][7].mv(3,'b');
    //Bishops
    current[0][2].mv(2,'b');
    current[7][2].mv(2,'b');
    current[0][5].mv(2,'b');
    current[7][5].mv(2,'b');
    //Horses
    current[0][1].mv(4,'b');
    current[0][6].mv(4,'b');
    current[7][1].mv(4,'b');
    current[7][6].mv(4,'b');
    //Queens
    current[0][3].mv(6,'b');
    current[7][3].mv(6,'w');
    //Kings
    current[0][4].mv(5,'b');
    current[7][4].mv(5,'w');



    


    
    
}

void prtBoard(board b){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(b.current[i][j].id == 0) cout<<"O ";
            if(b.current[i][j].id == 1) cout<<"P ";
            if(b.current[i][j].id == 2) cout<<"B ";
            if(b.current[i][j].id == 3) cout<<"R ";
            if(b.current[i][j].id == 4) cout<<"H ";
            if(b.current[i][j].id == 5) cout<<"K ";
            if(b.current[i][j].id == 6) cout<<"Q ";
        }
        cout<<endl;
    }
}


int main(){

    board b;
    b.init_board();
    // cout << b.current[0][0].id << endl;
    // prtMoves(b.current[1][0]);
    prtBoard(b);
    
}