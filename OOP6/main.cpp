#include "UI.h"

int main()
{
	Repository repository{};
	Service controller{ repository };
	
	UI ui{controller};
	ui.run();
	return 0;
}

