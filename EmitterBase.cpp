#include "Nel.h"

namespace nel {

	//エミッタのパラメータ値の変化量を求めます
	void CEmitterBase::FindAmountChange() {
		if (ELifeTimeRange > ELifeTime) ELifeTimeRange = ELifeTime - 1;
		ELifeTime = (unsigned int)(ELifeTime + ELifeTimeRange * Random(-1, 1));
		EVelocity += (EVelocityRange * Random(-1, 1));
		ERotation *= (ERotationRange * Random(-1, 1));
	}
}