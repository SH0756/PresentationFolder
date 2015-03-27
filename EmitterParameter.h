namespace nel {

	//�G�~�b�^�p�����[�^
	struct EmitterParameter {
	public:
		wstring					Name;						//�G�~�b�^��
		CVector					PositionRange;				//�����ʒu�̕�
		CVector					InitVelocity;				//���������x
		CVector					InitVelocityRange;			//���������x�̕�
		CVector					Velocity;					//�����x�̕ω���
		CVector					VelocityRange;				//�����x�̕�
		CQuaternion				InitRotation;				//������]��
		CQuaternion				InitRotationRange;			//������]�ʂ̕�
		CQuaternion				Rotation;					//��]�ʂ̕ω���
		CQuaternion				RotationRange;				//��]�ʂ̕�
		unsigned int			LifeTime;					//�������ԁi�t���[���P�ʁj
		unsigned int			LifeTimeRange;				//�������Ԃ̕�
		vector<wstring>			EGenerationList;			//�G�~�b�^�������X�g
		vector<unsigned int>	EInterval;					//�G�~�b�^�����Ԋu
		vector<unsigned int>	EProduction;				//�G�~�b�^������
		vector<wstring>			PGenerationList;			//�p�[�e�B�N���������X�g
		vector<unsigned int>	PInterval;					//�p�[�e�B�N�������Ԋu
		vector<unsigned int>	PProduction;				//�p�[�e�B�N��������

		//�R���X�g���N�^

		//�����Ȃ��R���X�g���N�^
		EmitterParameter() :
			Name(L""),
			PositionRange(CVector()),
			InitVelocity(CVector()), InitVelocityRange(CVector()), Velocity(CVector()), VelocityRange(CVector()), 
			InitRotation(CQuaternion()), InitRotationRange(CQuaternion()), Rotation(CQuaternion()), RotationRange(CQuaternion()), 
			LifeTime(0), LifeTimeRange(0) {}

		void Movement() {
			if (LifeTimeRange > LifeTime) LifeTimeRange = LifeTime - 1;
			LifeTime = (unsigned int)(LifeTime + LifeTimeRange * Random(-1, 1));
			Velocity += (VelocityRange * Random(-1, 1));
			Rotation *= (RotationRange * Random(-1, 1));
		}

		//�p�����[�^�l��Ԃ��܂�
		EmitterParameter& GetParameter() { return *this; }
	};
}