#include<simplecpp>

void MapTitle()
{
    Text Title(100,100, "InstIITute MAP");
    Title.imprint();
}

void LakeSide1()
{
    Rectangle Lake(246,600,492,300);
    Lake.setColor(COLOR(0,100,255));
    Lake.setFill();
    Lake.imprint();
}
void LakeSide2()
{
    Rectangle Lake1(246,400,492,100);
    Lake1.setColor(COLOR(0,100,255));
    Lake1.setFill();
    Lake1.imprint();
}
void LakeSide3()
{
    Rectangle Lake2(350,650,700,100);
    Lake2.setColor(COLOR(0,100,255));
    Lake2.setFill();
    Lake2.imprint();
}



void theFirstMatrices(int D[20][20],int S[20][20]){

    for(int i=0;i<20;i++){//point which are not directly conencted
        for(int j=0;j<20;j++){D[i][j]=100000;}
    }

    for (int i=0;i<20;i++){//diagonal elements
            D[i][i]=0;
    }

    D[17][1]=D[1][17]=100000;
    D[19][6]=D[6][19]=100000;
    D[19][7]=D[7][19]=100000;
    D[19][11]=D[11][19]=100000;
    D[0][1]=D[1][0]=200;
    D[2][1]=D[1][2]=400;
    D[3][1]=D[1][3]=100000;
    D[4][1]=D[1][4]=100000;
    D[1][5]=D[5][1]=100000;
    D[1][13]=D[13][1]=650;
    D[2][3]=D[3][2]=60;
    D[2][13]=D[13][2]=220;
    D[3][4]=D[4][3]=10;
    D[3][5]=D[5][3]=100000;
    D[3][8]=D[8][3]=150;
    D[4][5]=D[5][4]=100000;
    D[7][5]=D[5][7]=100000;
    D[4][8]=D[8][4]=140;
    D[6][5]=D[5][6]=150;
    D[6][7]=D[7][6]=20;
    D[9][8]=D[8][9]=160;
    D[10][9]=D[9][10]=100000;
    D[11][9]=D[9][11]=130;
    D[11][10]=D[10][11]=120;
    D[12][11]=D[11][12]=100;
    D[13][12]=D[12][13]=110;
    D[14][13]=D[13][14]=260;
    D[15][13]=D[13][15]=300;
    D[15][14]=D[14][15]=130;
    D[16][14]=D[14][16]=14;
    D[17][14]=D[14][17]=130;
    D[16][15]=D[15][16]=110;
    D[17][16]=D[16][17]=71;
    D[18][17]=D[17][18]=230;
    D[19][4]=D[4][19]=80;
    D[19][1]=D[1][19]=550;
    D[19][5]=D[5][19]=100;


    for(int i=0;i<20;i++)
        {
        for(int j=0;j<20;j++)
        {


            S[i][j]=i;
        }
        }
}


void iterate(int D[20][20], int S[20][20]){
    for(int k=0;k<20;k++){
        for (int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];S[i][j]=S[k][j];
                }
            }
        }
    }
}




void node(int x, int y){
Rectangle c(x,y,8,8);
c.setColor(COLOR(0,255,0));
c.setFill();
c.imprint();
}

void path(int x, int y, int x1, int y1)

{
    Line L(x,y,x1,y1);
    L.imprint();
}



struct points{
float x, y;
string name;
};

void namesOfNodes(points name[20])
{
    for(int i=0; i<20; i++)
    {
    Text nameNode(name[i].x,name[i].y-10,name[i].name);
    nameNode.imprint();
    }

}

void seq(int S[20][20], points name[20],int p, int q)
{
    do
    {
        int t=S[p][q];

        Line l(name[q].x,name[q].y,name[t].x,name[t].y);
        l.setColor(COLOR(255,0,0));
        l.imprint();


        q=t;
    }
    while(q!=S[p][q]);

        Line l(name[q].x,name[q].y,name[p].x,name[p].y);
        l.setColor(COLOR(255,0,0));
        l.imprint();
}




int Click(points places[20])
{
    int pos = getClick();
    int X = pos/65536;
    int Y = pos%65536;
    for(int i=0; i<20; i++)
    {
        if((X<=places[i].x+4&&X>=places[i].x-4)&&(Y<=places[i].y+4&&Y>=places[i].y-4))
           return i;
        else
        Text InvalidClick(300,500,"Please select out of the given places only!!");
    }


}


main_program{

int D[20][20], S[20][20];
theFirstMatrices(D,S);
iterate(D,S);
initCanvas("InstIITute MAP", 1040,700);
MapTitle();
LakeSide1();
LakeSide2();
LakeSide3();
points places[20];
places[0].x=440*2;
places[1].x=440*2;
places[2].x=296*2;
places[3].x=384*2;
places[4].x=384*2;
places[5].x=444*2;
places[6].x=444*2;
places[7].x=384*2;
places[8].x=348*2;
places[9].x=304*2;
places[10].x=248*2;
places[11].x=248*2;
places[12].x=248*2;
places[13].x=248*2;
places[14].x=144*2;
places[15].x=144*2;
places[16].x=116*2;
places[17].x=88*2;
places[18].x=48*2;
places[19].x=832;

places[19].y=168;
places[0].y=364*1.75;
places[1].y=324*1.75;
places[2].y=240*1.75;
places[3].y=104*1.75-8;
places[4].y=96*1.75-16;
places[5].y=80*1.75;
places[6].y=16*1.75;
places[7].y=16*1.75;
places[8].y=96*1.75-16;
places[9].y=96*1.75-16;
places[10].y=112*1.75-40;
places[11].y=128*1.75;
places[12].y=148*1.75;
places[13].y=188*1.75;
places[14].y=168*1.75-8;
places[15].y=168*1.75-24;
places[16].y=152*1.75-8;
places[17].y=144*1.75-8;
places[18].y=132*1.75;

places[0].name="Som";
places[1].name="Convocation Hall";
places[2].name="IITB Gymkhana";
places[3].name="SAC";
places[4].name="Hostel 1";
places[5].name="DRDO Apartments";
places[6].name="Hostel 15";
places[7].name="Hostel 16";
places[8].name="Hostel 2";
places[9].name="Hostel 3";
places[10].name="Hostel 4";
places[11].name="Tansa House";
places[12].name="SBI ATM";
places[13].name="Campus Hub";
places[14].name="Hostel 7";
places[15].name="Hostel 9";
places[16].name="Canara ATM";
places[17].name="Hostel 6";
places[18].name="Hostels 12,13 &14";

for(int i=0;i<19;i++){
    node(places[i].x,places[i].y);
}

path(places[0].x+4,places[0].y,places[1].x+4,places[1].y);
path(places[0].x-4,places[0].y,places[1].x-4,places[1].y);
path(places[2].x,places[2].y-4,places[1].x+4,places[1].y);
path(places[2].x,places[2].y+4,places[1].x-4,places[1].y);
path(places[13].x,places[13].y-4,places[2].x+4,places[2].y);
path(places[13].x,places[13].y+4,places[2].x-4,places[2].y);
path(places[18].x,places[18].y-4,places[13].x+4,places[13].y);
path(places[18].x,places[18].y+4,places[13].x-4,places[13].y+4);
path(places[10].x-4,places[10].y,places[13].x-4,places[13].y);
path(places[10].x+4,places[10].y,places[13].x+4,places[13].y);
path(places[9].x,places[9].y-6,places[11].x+4,places[11].y-8);
path(places[9].x-4,places[9].y+4,places[11].x,places[11].y+4);
path(places[4].x+4,places[4].y+4,places[9].x+4,places[9].y);
path(places[4].x-4,places[4].y+8,places[9].x-4,places[9].y+4);
path(places[3].x-4,places[3].y,places[4].x-4,places[4].y);
path(places[3].x+4,places[3].y,places[4].x+4,places[4].y);
path(places[19].x,places[19].y,places[4].x+4,places[4].y+4);
path(places[19].x-4,places[19].y+4,places[4].x-4,places[4].y+8);
path(places[19].x+2,places[19].y+6,places[5].x-4,places[5].y+4);
path(places[19].x-2,places[19].y-2,places[5].x-2,places[5].y-6);
path(places[5].x+4,places[5].y,places[6].x+4,places[6].y);
path(places[5].x-4,places[5].y,places[6].x-4,places[6].y);
path(places[7].x,places[7].y-4,places[6].x,places[6].y-4);
path(places[7].x,places[7].y+4,places[6].x,places[6].y+4);
path(places[19].x-4,places[19].y,places[1].x-4,places[1].y);
path(places[19].x+4,places[19].y+4,places[1].x+4,places[1].y);
namesOfNodes(places);
Text ts(300,500,"Please click on the source position.");
int p=Click(places);

ts.hide();

Text td(300,500,"Please click on the destination position.");
int q=Click(places);

td.hide();

Text tsd1(200,500,"The shortest distance between the two locations  in meters is ");
Text tsd2(450,500,D[p][q]);

seq(S,places,p,q);
wait(1000);


}




