#include <iostream>
#include <assert.h>

class Weapon
{
public:
    void Use() {}
};

class Sword : public Weapon
{
};

class Player
{
    std::shared_ptr<Weapon> weapon = nullptr;
    
public:
    Player(std::shared_ptr<Weapon> weapon1) : weapon(std::move(weapon1)) 
    {
    }
    /* いらない物は move で所有権を移し、無駄を減らす。
       こうすることで、メモリの使用効率が上がる*/

    Player(std::shared_ptr<Sword> sword) : weapon(std::move(sword))
    {
        std::cout << weapon.use_count() << std::endl;
        std::cout << sword.use_count() << std::endl;
    }

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

    /*auto a = std::make_shared<Player>(std::make_shared<Weapon>());
    std::cout << "a: " << a.use_count() << std::endl;
    std::cout << std::endl;

    auto b = a;
    std::cout << "a: " << a.use_count() << std::endl; 
    std::cout << "b: " << b.use_count() << std::endl;
    std::cout << std::endl;

    auto c = std::move(a);
    std::cout << "a: " << a.use_count() << std::endl;
    std::cout << "b: " << b.use_count() << std::endl;
    std::cout << "c: " << c.use_count() << std::endl;

    assert(a != nullptr);
    a->Attack();*/

	auto sword = std::make_shared<Sword>();
    Player p1(std::move(sword));
}
