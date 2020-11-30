int Merge_cldfunc(int row,int clo,int direction){
	if(board[row][clo]){
		if(value == board[row][clo]){
			if_merged = 1;
			value *= 2;
			maxvalue = MAX(maxvalue,value);
            if(direction == UP || direction == DOWN){
                board[locate][clo] = value;
            }
            else{
                board[row][locate] = value;
            }
			board[row][clo] = 0;
			value = 0;
			locate = 0;
		}
		else{
			value = board[row][clo];
            if(direction == UP || direction == DOWN){
                locate = row;
            }
			else{
                locate = clo;
            }
		}
	}
}