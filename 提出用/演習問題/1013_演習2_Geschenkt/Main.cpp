#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <random>
#include <sstream>
#include <string>
#include <vector>
enum class Action { Take, Pass };
class Player {
private:
 std::string name;
 int chips = 11;
 std::vector<int> cards;
public:
 explicit Player(std::string name):name(std::move(name)) {}
 virtual ~Player() = default;
 const std::string& GetName() const { return name; }
 int GetChips() const { return chips; }
 const std::vector<int>& GetCards() const { return cards; }
 bool PayChip() { if(chips==0) return false; --chips; return true; }
 void TakeCard(int card, int pot) { cards.push_back(card); std::sort(cards.begin(),cards.end()); chips+=pot; }
 int CardPoints() const { int sum=0, previous=-1; for(int card:cards) { if(card!=previous+1) sum+=card; previous=card; } return sum; }
 int Score() const { return CardPoints()-chips; }
 int AddedPoints(int card) const {
  auto values=cards; values.push_back(card); std::sort(values.begin(),values.end());
  int sum=0, previous=-1; for(int value:values) { if(value!=previous+1) sum+=value; previous=value; }
  return sum-CardPoints();
 }
 virtual Action ChooseAction(int card,int pot)=0;
 void Show() const { std::cout<<name<<" チップ："<<chips<<" カード："; for(int card:cards) std::cout<<card<<' '; std::cout<<'\n'; }
};
class HumanPlayer : public Player {
public:
 HumanPlayer():Player("あなた") {}
 Action ChooseAction(int,int) override {
  for(;;) {
   std::cout<<"1：取る  2：チップを払う > "; std::string line;
   if(!std::getline(std::cin,line)) { std::cout<<"入力終了のため取ります。\n"; return Action::Take; }
   if(line=="1") return Action::Take;
   if(line=="2") return Action::Pass;
   std::cout<<"1または2を入力してください。\n";
  }
 }
};
class CPUPlayer : public Player {
public:
 explicit CPUPlayer(std::string name):Player(std::move(name)) {}
 Action ChooseAction(int card,int pot) override { return AddedPoints(card)-pot<=3 || GetChips()<=2 ? Action::Take : Action::Pass; }
};
class Game {
private:
 std::vector<std::unique_ptr<Player>> players;
 std::vector<int> deck;
public:
 void Initialize() {
  players.clear(); players.push_back(std::make_unique<HumanPlayer>());
  players.push_back(std::make_unique<CPUPlayer>("CPU1")); players.push_back(std::make_unique<CPUPlayer>("CPU2"));
  deck.resize(33); std::iota(deck.begin(),deck.end(),3);
  std::mt19937 generator(std::random_device{}()); std::shuffle(deck.begin(),deck.end(),generator); deck.resize(24);
 }
 void Run() {
  Initialize(); std::size_t turn=0;
  for(int card:deck) {
   int pot=0; std::cout<<"\n公開カード："<<card<<'\n';
   for(;;) {
    for(const auto& player:players) player->Show();
    Player& player=*players[turn]; std::cout<<player.GetName()<<"の手番 ／ 場のチップ："<<pot<<'\n';
    Action action=player.GetChips()==0 ? Action::Take : player.ChooseAction(card,pot);
    if(action==Action::Take) { player.TakeCard(card,pot); std::cout<<player.GetName()<<"がカードとチップ"<<pot<<"枚を獲得。\n"; break; }
    if(player.PayChip()) { ++pot; std::cout<<player.GetName()<<"がチップを1枚支払いました。\n"; turn=(turn+1)%players.size(); }
   }
   // 取ったプレイヤーが次のカードでも最初に選びます。
  }
  int best=players.front()->Score(); for(const auto& player:players) best=std::min(best,player->Score());
  std::cout<<"\n最終結果（小さい得点が勝ち）\n";
  for(const auto& player:players) { player->Show(); std::cout<<"カード点："<<player->CardPoints()<<" 最終得点："<<player->Score(); if(player->Score()==best) std::cout<<" 勝者"; std::cout<<'\n'; }
 }
};
#ifndef GESCHENKT_TEST
int main() { Game game; game.Run(); }
#endif
