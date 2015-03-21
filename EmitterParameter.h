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
		vector<wstring>			GenerationList;				//�������X�g
		vector<unsigned int>	Interval;					//�����Ԋu
		vector<unsigned int>	Production;					//������

		//�R���X�^���N�^

		//�����Ȃ��R���X�g���N�^
		EmitterParameter() :
			Name(L""),
			PositionRange(CVector()),
			InitVelocity(CVector()), InitVelocityRange(CVector()), Velocity(CVector()), VelocityRange(CVector()), 
			InitRotation(CQuaternion()), InitRotationRange(CQuaternion()), Rotation(CQuaternion()), RotationRange(CQuaternion()), 
			LifeTime(0), LifeTimeRange(0) {}
	};
}