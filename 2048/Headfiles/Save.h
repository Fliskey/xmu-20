//-------- 2048GAME:save --------

/*--------------------------------------\
|                                       |
|   Author: Yuxiang Wang(Fliskey)       |
|   ID:     13720192200474              |
|   Email:  Fliskey@qq.com              |
|                                       |
|   Last update time:   Dec.2 2020      |
|                                       |
\--------------------------------------*/

extern int max_save_number;
extern int board[6][6];
extern int goal;
extern int maxvalue;
extern int save_goals[34];
extern int save_maxvalue[34]; 
extern int save_board[34][6][6];
extern int save_point;

//function declear
int save_push();
int save_pop();
int save_to_disk();
int load_from_disk();

int save_to_disk(){
    FILE *data = fopen("save.data","w");
    fprintf(data,"%d %d\n",maxvalue,goal);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            fprintf(data,"%d ",board[i][j]);
        }
    }
    fclose(data);
}

int load_from_disk(){
    FILE *data = fopen("save.data","r");
    if(data == NULL){
        fclose(data);
        return 0;
    } 
    fscanf(data,"%d %d",&maxvalue,&goal);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            fscanf(data,"%d",&board[i][j]);
        }
    }
    fclose(data);
    return 1;
}

int board_copy(int to[6][6],int from[6][6]){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            to[i][j] = from[i][j];
        }
    }
    return 1;
}

int save_push(){
    if(save_point >= max_save_number){
        save_point = max_save_number;
        for(int i=2;i<=max_save_number;i++){
            board_copy(save_board[i-1],save_board[i]);
        }
        board_copy(save_board[save_point],board);
        save_goals[save_point] = goal;
        save_maxvalue[save_point] = maxvalue;
    }
    else{
        save_point++;
        board_copy(save_board[save_point],board);
        save_goals[save_point] = goal;
        save_maxvalue[save_point] = maxvalue;
    }
}

int save_pop(){
    if(save_point <= 1){
        return 0;
    }
    
    save_point--;
    board_copy(board,save_board[save_point]);
    goal = save_goals[save_point];
    maxvalue = save_maxvalue[save_point];

    if(save_point < 1){
        save_point = 1;
    }    
    return 1;
}
