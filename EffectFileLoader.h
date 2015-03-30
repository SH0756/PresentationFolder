namespace nel {

	//---------------------------------------------------------------------------------------------------------------------------
	//�p�[�e�B�N���t�@�C���̑���N���X
	class CParticleFile : public ParticleParameter {
	public:
		wstring ParticleFileName;			//�ǂݍ��񂾃p�[�e�B�N���t�@�C����

		//�����Ȃ��R���X�g���N�^
		CParticleFile() : ParticleFileName(NULL), ParticleParameter() {}

		//filename ����p�����[�^�l��ǂݍ��݂܂�
		CParticleFile(wstring filename) : ParticleFileName(filename), ParticleParameter() {
			ReadParticleFile(filename);
		}

		//�t�@�C������p�[�e�B�N���̃p�����[�^�l��ǂݍ��݂܂��i.particle�`���j
		void ReadParticleFile(wstring filename);
	};

	//�p�[�e�B�N���t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateParticleFile(wstring filename);


	//----------------------------------------------------------------------------------------------------------------------------
	//�G�~�b�^�t�@�C���̑���N���X
	class CEmitterFile : public EmitterParameter {
	public:
		wstring EmitterFileName;			//�ǂݍ��񂾃G�~�b�^�t�@�C����

		//�����Ȃ��R���X�g���N�^
		CEmitterFile() : EmitterFileName(NULL), EmitterParameter() {}

		//filename ����p�����[�^�l��ǂݍ��݂܂�
		CEmitterFile(wstring filename) : EmitterFileName(filename), EmitterParameter() {
			ReadEmitterFile(filename);
		}

		//�t�@�C������G�~�b�^�̃p�����[�^�l��ǂݍ��݂܂��i.emitter�`���j
		void ReadEmitterFile(wstring filename);
	};

	//�G�~�b�^�t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateEmitterFile(wstring filename);
}
