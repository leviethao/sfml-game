#include "World.h"
#include "Ball.h"
#include "Constant.h"
#include <iostream>
#include "FireParticle.h"
#include <exception>

int score = 1;

World::World(sf::RenderTarget &target)
	: mSceneGraph()
	, mWorldBound()
	, mTarget(target)
	, ball(nullptr)
	, mFragments()
{
	mSceneGraph = new SceneNode();
	mWorldBound = new sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

World::~World()
{
	/*delete mSceneGraph;
	delete mWorldBound;
	delete mFont;
	delete mTxtScore;
	delete mTopEdge;
	delete mSpriteTop;
	delete mFragment;*/
}

void World::init()
{
	//create ball
	ball = new Ball();
	ball->setVelocity(sf::Vector2f(200, 200));
	ball->setPosition(30, 30);
	mSceneGraph->attachChild(ball);

	//create top edge
	mTopEdge = new sf::Texture();
	mTopEdge->loadFromFile("images/topEdge.png");
	mSpriteTop = new sf::Sprite(*mTopEdge);
	mSpriteTop->setScale(1.0 * SCREEN_WIDTH / mSpriteTop->getTextureRect().width, mSpriteTop->getScale().y);

	mWorldBound->top += mTopEdge->getSize().y * mSpriteTop->getScale().y;
	ball->setWorldBound(*mWorldBound);

	//Text and font
	mFont = new sf::Font();
	if (!mFont->loadFromFile("fonts/Sansation.ttf"))
		std::cout << "font file is not found!" << std::endl;

	mTxtScore = new sf::Text("0", *mFont, 20);
	mTxtScore->setColor(sf::Color::Yellow);
	mTxtScore->setStyle(sf::Text::Bold);
	mTxtScore->setPosition(10, 10);

	//Particle
	sf::Texture fireTexture;
	if (!fireTexture.loadFromFile("images/Particle.png"))
		std::cout << "particle image file not found!" << std::endl;

	/*FireParticle *fire = new FireParticle(fireTexture);
	fire->setPosition(0, 100);
	mSceneGraph->attachChild(fire);*/

	//background music
	sf::Music *bgMusic = new sf::Music();
	if (!bgMusic->openFromFile("sounds/inspiring-days.ogg"))
	{
		std::cout << "Can not open music file" << std::endl;
	}
	else
	{
		bgMusic->setLoop(true);
		bgMusic->play();
	}

	//background image
	mBgTexture = new sf::Texture();
	if (!mBgTexture->loadFromFile("images/background.jpg"))
	{
		std::cout << "can not load background image file" << std::endl;
	}
	else
	{
		mBackground = new sf::Sprite(*mBgTexture);
		mBackground->setScale((mWorldBound->width - mWorldBound->left) / mBgTexture->getSize().x, (mWorldBound->height - mWorldBound->top) / mBgTexture->getSize().y);
		mBackground->setPosition(mWorldBound->left, mWorldBound->top);
	}

}

void World::update(sf::Time dt)
{
	mTxtScore->setString("Score: " + std::to_string(score));
	mSceneGraph->update(dt);
	if (ball->isCollision)
	{
		Fragment *fragment = new Fragment(ball->getPosition(), sf::seconds(2), ball->getColor());
		mFragments.push_back(fragment);
	}

	for (auto fragment : mFragments)
		fragment->update(dt);


	while (!mFragments.empty())
	{
		if ((*mFragments.begin())->getLifeTime() <= sf::Time::Zero)
		{
			auto fragment = *mFragments.begin();
			mFragments.erase(mFragments.begin());
			delete fragment;
		}
		else
		{
			break;
		}
	}

}

void World::draw()
{
	mTarget.draw(*mBackground);
	mTarget.draw(*mSpriteTop);
	mTarget.draw(*mTxtScore);
	mTarget.draw(*mSceneGraph);

	for (auto fragment : mFragments)
		mTarget.draw(*fragment);
}