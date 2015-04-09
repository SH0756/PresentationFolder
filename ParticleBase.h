namespace nel {
	class CParticleBase : public CParticleFile {
	public:
		CParticleBase(wstring filename) : CParticleFile(filename) {
			FindAmountChange();
		}

		//パーティクルのパラメータ値の変化量を求める
		void FindAmountChange();
	};
}