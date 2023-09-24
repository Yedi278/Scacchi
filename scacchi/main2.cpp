#include <iostream>
using namespace std;

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

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

    //PAWNS
    for(int i=0;i<8;i++){   

        current[1][i].mv(1,'b');
        
        current[6][i].mv(1,'w');

    }
    //Rooks
    current[0][0].mv(3,'b');
    current[0][7].mv(3,'b');
    current[7][0].mv(3,'w');
    current[7][7].mv(3,'w');
    //Bishops
    current[0][2].mv(2,'b');
    current[7][2].mv(2,'w');
    current[0][5].mv(2,'b');
    current[7][5].mv(2,'w');
    //Horses
    current[0][1].mv(4,'b');
    current[0][6].mv(4,'b');
    current[7][1].mv(4,'w');
    current[7][6].mv(4,'w');
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
            if(b.current[i][j].id == 1) if(b.current[i][j].color == 'w') cout<<"P "; else if(b.current[i][j].color == 'b') cout << RED "P " << RESET;
            if(b.current[i][j].id == 2) if(b.current[i][j].color == 'w') cout<<"B "; else if(b.current[i][j].color == 'b') cout << RED "B " << RESET;
            if(b.current[i][j].id == 3) if(b.current[i][j].color == 'w') cout<<"R "; else if(b.current[i][j].color == 'b') cout << RED "R " << RESET;
            if(b.current[i][j].id == 4) if(b.current[i][j].color == 'w') cout<<"H "; else if(b.current[i][j].color == 'b') cout << RED "H " << RESET;
            if(b.current[i][j].id == 5) if(b.current[i][j].color == 'w') cout<<"K "; else if(b.current[i][j].color == 'b') cout << RED "K " << RESET;
            if(b.current[i][j].id == 6) if(b.current[i][j].color == 'w') cout<<"Q "; else if(b.current[i][j].color == 'b') cout << RED "Q " << RESET;
        }
        cout<<endl;
    }
}

int* move(){
    
    string a;
    cin >> a;
    int p[2];
    if(a[0]<= 72 && a[0]>64) p[0]= a[0]-65;
    else if(a[0]<= 104 && a[0]>96) p[0]= a[0]-97;
    else cout << "wrong notation";
    p[1] = a[1];
    return p;


}

void init_game(board b){
    
    b.init_board();
    prtBoard(b);
    bool isGameOver = false;

    // while(!isGameOver){
    //     cout << "Che mossa vuoi fare?";
    
    // }
    
}


int main(){

    board b;
    // init_game(b);

    int *p;
    p = move();
    cout << p[0];
    
}