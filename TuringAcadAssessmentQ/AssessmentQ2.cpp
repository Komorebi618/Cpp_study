#include <iostream>
using namespace std;
// C/C++:
//  -------------------- 数据设计 --------------------
/*
    棋盘:
        board[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: board[3][6] = 1  表示(3,6)的位置是黑子
*/
int board[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;

// -------------------- 数据设计 --------------------

// -------------------- service --------------------
/*
    负责人: 张三
    功能: init: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/*
    *难点1
    负责人: 张三
    功能: isWin: 根据传入的坐标(board对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/*
    负责人: 张三
    功能: playerMove: 在指定位置落子
        如果board[x][y]是空地 则修改board[x][y]的值:改为相应颜色(flag对应颜色)        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------

// -------------------- view --------------------
/*
    负责人: 张三
    功能: menuView: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        while(1){
            1. 展示选项
            2. 用户输入
            3. 根据输入进行对应处理
                进入游戏: 调用游戏界面函数gameView();
                进入设置: 打印敬请期待... 重新循环
                退出游戏: 调用exit(0);
        }
    参数: void
    返回值: void
*/
void menuView();

/*
    负责人: 张三
    功能: gameView_ShowBoard: 根据board数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowBoard();

/*
    负责人: 张三
    功能: winView:
        根据flag的值  打印游戏胜利界面  用户可以按任意键(使用getch函数)退出当前界面
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: gameView: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowBoard())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    menuView();
    return 0;
}

void init()
{
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            board[i][j] = 0;
        }
    }
    flag = 0; // 当前回合设为黑棋
}

int isWin(int x, int y)
{
    int color = (flag % 2) == 0 ? 1 : 2; // 当前落子颜色
    int count = 1;

    // 纵向判断
    for (int i = 1; i < 5; i++){
        if(x - i < 0){
            break;
        }
        if(board[x-i][y]==color){
            count++;
            if (count == 5){
                return color;
            }
            continue;
        }else{
            break;
        }
    }
    for (int i = 1; i < 5; i++){
        if(x + i >= 19){
            break;
        }
        if(board[x+i][y]==color){
            count++;
            if (count == 5){
                return color;
            }
            continue;
        }else{
            break;
        }
    }
    count = 1;

    // 横向判断
    for (int i = 1; i < 5; i++){
        if(y - i < 0){
            break;
        }
        if(board[x][y-i]==color){
            count++;
            if (count == 5){
                return color;
            }
            continue;
        }else{
            break;
        }
    }
    for (int i = 1; i < 5; i++){
        if(y + i >= 19){
            break;
        }
        if(board[x][y+i]==color){
            count++;
            if (count == 5){
                return color;
            }
            continue;
        }else{
            break;
        }
    }
    count = 1;

    // 斜向判断(左上-右下)
    for (int i = 1; i < 5; i++){
        if(x - i < 0 || y - i < 0){
            break;
        }
        if(board[x-i][y-i]==color){
            count++;
            if (count == 5){
                return color;
            }
            continue;
        }else{
            break;
        }
    }
    for (int i = 1; i < 5; i++){
        if(x + i >= 19 || y + i >= 19){
            break;
        }
        if(board[x+i][y+i]==color){
            count++;
            if (count == 5){
                return color;
            }
            continue;
        }else{
            break;
        }
    }
    count = 1;

    // 斜向判断(右上-左下)
    for (int i = 1; i < 5; i++){
        if(x - i < 0 || y + i >= 19){
            break;
        }
        if(board[x-i][y+i]==color){
            count++;
            if (count == 5){
                return color;
            }
            continue;
        }else{
            break;
        }
    }
    for (int i = 1; i < 5; i++){
        if(x + i >= 19 || y - i < 0){
            break;
        }
        if(board[x+i][y-i]==color){
            count++;
            if (count == 5){
                return color;
            }
            continue;
        }else{
            break;
        }
    }

    return 0;
}

int playerMove(int x, int y)
{
    if(board[x][y] != 0)
    {
        return 0; // 落子失败
    }else{
        if (flag % 2 == 0)
        {
            board[x][y] = 1; // 黑子落子
        }else{
            board[x][y] = 2; // 白子落子
        }
        return 1; // 落子成功
    }

    return 0;
}

void menuView()
{
    int input; // input用于接收用户输入的指令
    while (1)
    {
        cout << "1. 进入游戏" << endl;
        cout << "2. 进入设置" << endl;
        cout << "3. 退出游戏" << endl;
        cin >> input;
        if (input == 1)
        {
            gameView();
        }
        else if (input == 2)
        {
            cout << "敬请期待..." << endl;
        }
        else if (input == 3)
        {
            exit(0);
        }
    }
}

void gameView_ShowBoard()
{
    cout << "0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18(x)" << "\n\n";
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << i << " ";
        if(i==18){
            cout << "(y)" << endl;
        }else{
            cout << endl;
        }
    }
}

void winView()
{
    if(flag % 2 == 0)
    {
        cout << "黑子胜利!" << endl;
    }else{
        cout << "白子胜利!" << endl;
    }
    cout << "按任意键退出当前界面..." << endl;
    cin.ignore();
    getchar();
}

void gameView()
{
    init(); // 初始化游戏数据
    while (1)
    {
        gameView_ShowBoard(); // 打印游戏界面
        int x, y; // 玩家落子坐标
        cout << "请输入落子坐标(x y): ";
        cin >> y >> x; // 接收玩家坐标输入，为了符合数组下标，输入时先输入y再输入x
        if (playerMove(x, y) == 0)
        {
            cout << "落子失败! 该位置已有棋子." << endl;
            continue; // 落子失败 重新开始循环
        }
        if (isWin(x, y) != 0)
        {
            winView(); // 游戏胜利
            break; // 结束当前界面
        }
        flag++; // 切换玩家
    }
    
}