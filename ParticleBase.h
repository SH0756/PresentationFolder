namespace nel {
	class CParticleBase : public CParticleFile {
	public:
		CParticleBase(wstring filename) : CParticleFile(filename) {}

		//�p�[�e�B�N���̃p�����[�^�l�̕ω��ʂ����߂�
		void Movement();
	};
}