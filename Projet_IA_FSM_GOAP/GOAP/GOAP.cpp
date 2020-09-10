#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// -----------------------------------------------------------------------
/*
 *  GOAP SOLVER ==> on lui donne state now, state objectif, et il cherche la meilleur chemin
 *  
 *  ACTION ==>
 *  
 *  PRECONDITION ==>
 *
 *  une action, qui a un cost, pointe vers plusieurs precondition
 *      chaque precondition prevois plusieurs autre action
 *          chaque action a un effet final (exemple : +1 bois)
 *
 *  action = chop wood
 *      -> condition = avoir villageois de disponnible
 *          -non ?
 *              -> Create villageois
 *                  -> condition = avoir 10 de bouffe
 *                      -oui ?
 *          -oui ?
 *              -> reassign villageois
 *
 * actual state
 *  - wood = 50
 *  - stone = 50
 *  - food = 100
 *  - people = 6
 *
 *  target state
 *  - wood = 100
 *  - stone = 100
 *  - food = 200
 *  - people = 12
 *
 * target state == actual state ==> newTargetState = actual *2
 *  - wood = 150
 *  - stone = 100
 *  - food = 100
 *  - people = 60
 */