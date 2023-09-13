#include <iostream>
#include <string>
using namespace std;

struct Monster
{
    string MonsterName;
    int MonsterHealth = 0;
    int MonsterAttack = 0;
};

struct Player
{
    string Playername;
    int PlayerHealth = 0;
    int PlayerAttack = 0;
    int PlayerDefense = 0;
    int PlayerHeal = 0;
};

int main()
{
    // 몬스터 기본 정보
    Monster m;
    m.MonsterName = "Orc";
    m.MonsterHealth = 270;
    m.MonsterAttack = 20;


    //플레이어 기본정보
    Player p;
    p.Playername = "Backgame";
    p.PlayerHealth = 100;
    p.PlayerAttack = 40;
    p.PlayerDefense = 15;
    p.PlayerHeal = 30;

    // 반복문에 필요한 코드
    string cmd;
    int turnCount = 0; // 전투 턴 카운터 변수

    cout << "지나가는 길에 몬스터가 길을 막고있다! ";
    cout << "도망치려했으나 몬스터와 눈이 마주쳤다. ";
    cout << "아무래도 몬스터를 쓰러뜨려야할 것 같다. 나는 무엇을 할까? " << endl;
    cout << endl;

    cout << "#미션등록# 10턴 안으로 몬스터 물리치기" << endl;
    cout << "Attack or Defense or Heal" << endl;

    while (m.MonsterHealth > 0 && p.PlayerHealth > 0 && turnCount < 10)
    {
        cin >> cmd;

        if (cmd == "Attack")
        {
            cout << endl;
            m.MonsterHealth -= p.PlayerAttack;
            cout << "오크의 체력을 40만큼 깎았다!" << " <" << m.MonsterHealth << ">" << endl;
            p.PlayerHealth -= m.MonsterAttack;
            cout << "아야! 오크의 공격에 체력이 20이 깎였다! (" << p.PlayerHealth << ")" << endl;
            cout << endl;
            cout << "나는 이제 무엇을 할까? (Attack or Defense or Heal)" << endl;
        }
        else if (cmd == "Defense")
        {
            p.PlayerHealth -= m.MonsterAttack - p.PlayerDefense; // 공격력에서 방어력을 뺀 값
            cout << endl;
            cout << "아야! 공격을 막아냈지만 체력이 " << m.MonsterAttack - p.PlayerDefense << "만큼 깎였다! (" << p.PlayerHealth << ")" << endl;
            cout << "나는 이제 무엇을 할까? (Attack or Defense or Heal)" << endl;
        }
        else if (cmd == "Heal")
        {
            p.PlayerHealth += p.PlayerHeal;
            cout << endl;
            cout << "체력을 회복 했다! (" << p.PlayerHealth << ")" << endl;
            cout << "나는 이제 무엇을 할까? (Attack or Defense or Heal)" << endl;
        }

        turnCount++; // 턴 카운트 증가
    }

    if (m.MonsterHealth <= 0)
    {
        cout << endl;
        cout << "오크를 물리쳤다!" << endl;
        cout << "You Win!!" << endl;
    }
    else if (p.PlayerHealth <= 0)
    {
        cout << endl;
        cout << "오크에게 패배하고 말았다..." << endl;
        cout << "You Lose!" << endl;
    }
    else if (turnCount >= 10)
    {
        cout << endl;
        cout << "미션 클리어에 실패했습니다!" << endl;
        cout << "You Lose!" << endl;
    }

    return 0;
}