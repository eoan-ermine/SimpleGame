#pragma once

#include <string>
#include <string_view>

#include "../GameWindow/Game/GameObject/GameObject.h"

class AbstractPlayer;

class AbstractEffect: public GameObject {
private:
	std::string name, description;
    int duration, last;
    bool permanent;
public:
	AbstractEffect(std::string name, std::string description, int duration);
    AbstractEffect(int duration);
    ~AbstractEffect();

    virtual void action(AbstractPlayer* ply);

    int getDuration() const noexcept;
    int getRemains() const noexcept;
    bool isPermanent() const noexcept;
	
	void setDuration(int newDuration) noexcept;
	void setRemains(int newRemains) noexcept;
	void setPermanent(bool newPermanent) noexcept;
	
	std::string_view getName() const noexcept;
	std::string_view getDescription() const noexcept;
	
	void setName(std::string name) noexcept;
	void setDescription(std::string description) noexcept;
};
