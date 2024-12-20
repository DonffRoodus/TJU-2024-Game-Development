/****************************************************************
 * \file   WeatherSystem.h
 * \brief  The system to control the weather and broadcast weather information.
 * 
 * \author 4_of_Diamonds
 * \date   November 2024
 *********************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WeatherSystem.generated.h"

/**
 * 
 */
UCLASS()
class STARDEWVALLEY_API UWeatherSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
private:
	enum class Weather
	{
		Sunny,
		Cloudy,
		Rainy,
		Snowy
	};
	Weather weather_;
public:
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	/**
	 * \brief Change the weather, called on 8am and 8pm.
	 */
	void ChangeWeather();
	/**
	 * \brief Update the base temperature, called when the hour changes.
	 */
	void UpdateBaseTemperature();

public:
	//Getters
	int32 get_weather() { return static_cast<int32>(weather_); };

	//Setters
	void set_weather(int32 weather) { weather_ = static_cast<Weather>(weather); };
};
