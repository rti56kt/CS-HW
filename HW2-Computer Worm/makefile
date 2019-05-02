all: Launching_Attack Flooding_Attack Check_Attack worm
Launching_Attack: Launching_Attack.cpp
	g++ Launching_Attack.cpp -o l
Flooding_Attack: Flooding_Attack.cpp
	g++ Flooding_Attack.cpp -o f
Check_Attack: Check_Attack.cpp
	g++ Check_Attack.cpp -o c
worm: worm.cpp
	g++ worm.cpp -o worm
clean:
	rm -f Launching_Attack
	rm -f Flooding_Attack
	rm -f Check_Attack
	rm -f worm