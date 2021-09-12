struct line{
    char content[7];
    char drawstats ; 
};

struct player{
    char name[100] ; 
    int score ; 
};
struct box{
    char boxlines[4] ; 
    char centersym ; 
    char point;
};
struct board{
    struct line gamelines[17]; 
    char gamestats ;
    char playerturn ; 
    struct player players[2]; 
    struct box boxes[6];
}; 

