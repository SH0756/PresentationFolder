namespace nel {
	class CParticleBase : public CParticleFile {
	public:
		CParticleBase(wstring filename) : CParticleFile(filename) {}

		//パーティクルのパラメータ値の変化量を求める
		void Movement();
	};
}