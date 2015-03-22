namespace nel {

	//�p�[�e�B�N���t�@�C���̑���-----------------------------------------------------------------------------------------
	class CParticleFile {
	public:
		ParticleParameter* Param;

		//�����Ȃ��R���X�g���N�^
		CParticleFile() : Param(NULL) {}

		//filename ����p�����[�^�l��ǂݍ��݂܂�
		CParticleFile(wstring filename) {
			Param = new ParticleParameter;
			ReadParticleFile(filename, *Param);
		}

		//�t�@�C������p�[�e�B�N���̃p�����[�^�l��ǂݍ��݂܂��i.particle�`���j
		void ReadParticleFile(wstring filename, ParticleParameter& param);

		~CParticleFile() { delete Param; }
	};

	//�p�[�e�B�N���t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateParticleFile(wstring filename);


	//�G�~�b�^�t�@�C���̑���-----------------------------------------------------------------------------------------------
	class CEmitterFile {
	public:
		EmitterParameter* Param;

		//�����Ȃ��R���X�g���N�^
		CEmitterFile() : Param(NULL) {}

		//filename ����p�����[�^�l��ǂݍ��݂܂�
		CEmitterFile(wstring filename) {
			Param = new EmitterParameter;
			ReadEmitterFile(filename, *Param);
		}

		//�t�@�C������G�~�b�^�̃p�����[�^�l��ǂݍ��݂܂��i.emitter�`���j
		void ReadEmitterFile(wstring filename, EmitterParameter& param);

		~CEmitterFile() { delete Param; }
	};

	//�G�~�b�^�t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateEmitterFile(wstring filename);
}
