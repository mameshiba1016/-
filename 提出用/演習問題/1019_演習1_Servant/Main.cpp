#include "Saber.h"
#include "Archer.h"
#include "Rider.h"

int main()
{
    Saber saber;
    Archer archer;
    Rider rider;
    Servant* servants[] = { &saber, &archer, &rider };
    for (Servant* servant : servants)
    {
        servant->ShowProfile();
        servant->Attack();
    }
    return 0;
}
