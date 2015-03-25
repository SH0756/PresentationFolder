namespace nel {

	//�p�[�e�B�N���t�@�C���̑���-----------------------------------------------------------------------------------------
	class CParticleFile : public ParticleParameter {
	public:
		//�����Ȃ��R���X�g���N�^
		CParticleFile() {}

		//filename ����p�����[�^�l��ǂݍ��݂܂�
		CParticleFile(wstring filename) {
			ReadParticleFile(filename);
		}

		//�t�@�C������p�[�e�B�N���̃p�����[�^�l��ǂݍ��݂܂��i.particle�`���j
		void ReadParticleFile(wstring filename);
	};

	//�p�[�e�B�N���t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateParticleFile(wstring filename);


	//�G�~�b�^�t�@�C���̑���N���X-----------------------------------------------------------------------------------------------
	class CEmitterFile : public EmitterParameter {
	public:
		//�����Ȃ��R���X�g���N�^
		CEmitterFile() {}

		//filename ����p�����[�^�l��ǂݍ��݂܂�
		CEmitterFile(wstring filename) {
			ReadEmitterFile(filename);
		}

		//�t�@�C������G�~�b�^�̃p�����[�^�l��ǂݍ��݂܂��i.emitter�`���j
		void ReadEmitterFile(wstring filename);
	};

	//�G�~�b�^�t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateEmitterFile(wstring filename);
}
