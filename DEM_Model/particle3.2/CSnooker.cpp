#include "CSnooker.h"

const double PI = 3.1415926;

using namespace NApi;
using namespace NApiCore;
using namespace NApiFactory;

CSnooker::CSnooker() :
          m_numberCreated(0)
{

}

CSnooker::~CSnooker()
{

}

NApi::ECalculateResult CSnooker::createParticle(
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
                                        NApiCore::ICustomPropertyDataApi_1_0* simData)
{

    if(/*time > 1e-7 ||*/ m_numberCreated >= 952)
    {
        particleCreated = false;
        additionalParticleRequired = false;
        return eSuccess;
    }

    // Mark that we are creating a particle
    particleCreated = true;

    // Set some fixed values for all particles we create
    velX = 0.0;
    velY = 0.0;
    velZ = 0.0;

    angVelX = 0.0;
    angVelY = 0.0;
    angVelZ = 0.0;

    for (unsigned int i = 0; i < 9; i++)
    {
        orientation[i] = 0.0;
    }

    scale = 1.0;

    // Particle positions
    int c = m_numberCreated / 28;
    int i = m_numberCreated % 28;
    double angle = i * 2 * PI / 28;
    double radius = 0.00095;

    posX = ((-sin(angle))/ 40.02)-0.155;
    posY = ((cos(angle))/ 40.02)-((c * 10 * radius + (2 * radius))*0.37)+0.173;
    posZ = (c * 10 * radius + (2 * radius))+(((cos(angle))/ 40.02)*0.37)-0.319;

    strcpy(type, "particle");

    // Mark the particle as created
    m_numberCreated++;

    // We are creating 21 particles, if we've done them all
    // then no more are required
    // additionalParticleRequired = (500 != m_numberCreated);
    additionalParticleRequired = false;

    return eSuccess;
}

void CSnooker::getSmallestScale(double& scale, char type[NApi::API_BASIC_STRING_LENGTH]) const
{
	// Indicate to EDEM the type and scale of the particle that will have the smallest radius
	// so that EDEM can compute the Rayleigh time step

	std::string particleType = "particle";

	strcpy(type, particleType.c_str());

	scale = 1.0;
}