#include <iostream>
#include <assert.h>

class Weapon
{
public:
    void Use() {}
};

class Player
{
    std::shared_ptr<Weapon> weapon;
    
public:
    Player(std::shared_ptr<Weapon> weapon1) : weapon(std::move(weapon1)) 
    {
		std::cout << weapon.use_count() << std::endl;
        std::cout << weapon1.use_count() << std::endl;
    }
    /* いらない物は move で所有権を移し、無駄を減らす。
       こうすることで、メモリの使用効率が上がる*/

    void Attack()
    {
        if (weapon) weapon->Use();
    }
};

int main()
{
 //   auto wp = std::make_shared<Weapon>();

 //   // コピー(参照カウント +1)
 //   Player p(wp);
 //   // ムーブ(所有権を移動)
	//Player q(std::move(wp));

    auto a = std::make_shared<Weapon>();
    auto b = a;
    auto c = std::move(a);

    Player l(a);
    Player m(b);
    Player n(c);

    return 0;
}
