#include "Nel.h"

namespace nel {
	//�p�[�e�B�N���̃p�����[�^�l�̕ω��ʂ����߂�
	void CParticleBase::FindAmountChange() {
		if (PLifeTime < PLifeTimeRange) PLifeTimeRange = PLifeTime - 1;
		PLifeTime = (unsigned int)(PLifeTime + PLifeTimeRange * Random(-1, 1));
		PScale = (PEndScale - PInitScale) / (float)PLifeTime;
		PColor = (PEndColor - PInitColor) / (float)PLifeTime;
		PSpecularColor = (PEndSpecularColor - PInitSpecularColor) / (float)PLifeTime;
		PEmissiveColor = (PEndEmissiveColor - PInitEmissiveColor) / (float)PLifeTime;
		PRimColor = (PEndRimColor - PInitRimColor) / (float)PLifeTime;
		PVelocity += PVelocityRange * Random(-1, 1);
		PRotation += PRotationRange * Random(-1, 1);
	}
}