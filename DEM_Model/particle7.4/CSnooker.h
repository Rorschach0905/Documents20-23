#if !defined(csnooker_h)
#define csnooker_h

#include "IPluginParticleFactoryV2_1_0.h"
#include <string>

using namespace std;

class CSnooker : public NApiFactory::IPluginParticleFactoryV2_1_0
{
    public:
        /**
         * Constructor, does nothing
         */
        CSnooker();

        /**
         * Destructor, does nothing
         */
        virtual ~CSnooker();

        // Implementation of method from IPluginParticleFactoryV2_1_0
        virtual NApi::ECalculateResult createParticle(
                                           double  time,
                                           double  timestep,
                                           bool&   particleCreated,
                                           bool&   additionalParticleRequired,
                                           char    type[NApi::API_BASIC_STRING_LENGTH],
                                           double& scale,
                                           double& posX,
                                           double& posY,
                                           double& posZ,
                                           double& velX,
                                           double& velY,
                                           double& velZ,
                                           double& angVelX,
                                           double& angVelY,
                                           double& angVelZ,
                                           double  orientation[9],
                                           NApiCore::ICustomPropertyDataApi_1_0* propData,
                                           NApiCore::ICustomPropertyDataApi_1_0* simData);
										   

	virtual void getSmallestScale(double& scale, char type[NApi::API_BASIC_STRING_LENGTH]) const;
	
    private:
        /**
         * Number of particles created so far
         */
        unsigned int m_numberCreated;

};

#endif