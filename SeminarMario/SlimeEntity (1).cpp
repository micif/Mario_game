#include "SlimeEntity.h"

using namespace cv;
using namespace std;

EntityStatePtr CreateSlimeEnemy(std::string const& animationFolder)
{
	AnimationPtr animation(new Animation(animationFolder));
	bool isCyclic = true;

	IGraphicsComponentPtr graphicsPtr(
		new SingleAnimationGraphics(animation, isCyclic));

	IPhysicsComponentPtr nonCollidingPhysicsPtr = 
		make_shared<NonCollidingPhysicsDecorator>(
			make_shared<FixedWidgetPhysics>());

	return make_shared<EntityState>(graphicsPtr, nonCollidingPhysicsPtr);
}