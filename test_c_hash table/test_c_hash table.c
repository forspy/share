#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hash_table.h"
//hash�㷨��Ŀ����Ϊ�˿��ٲ���
//key-->value(������Ϣ)
//1.��θ���key�ּ��ϣ� 
//2.��ô���ܹ���ԱȽϾ��ȣ�
//3.��θ����ڼ�������key��
//4.���������Ѽ����ڵĽڵ㴮��������
//HASH��ϣ�㷨
//(1).��һ���ַ���-->����  Ȼ���������%N �õ���ֵλ��[0��N-1]֮�� ֻҪ�ַ����ܶ�����γ�[0,N-1]�ļ������кţ��γ�һ������
//(2).���ڲ�ͬ���ַ���������Ҫ���������ɲ�ͬ��key�� ͨ��hashɢ�У�Ҫɢ���㹻���� ����"hello"-->3 "hellm"-->5
int main()
{
	struct hash_table* t = create_hash_table(3);//����3������,��������Խ��ɢ��Խƽ��,����ֻ����4*n��
	//����
	//ע��void*����ת�ɶ������Ͷ���ʧ�棬��˿���ʹ��void*���ͱ�������
	hash_insert(t, "xiaoming", (void*)12);
	hash_insert(t, "xiaohong", (void*)36);
	//����򸲸�
	hash_set(t, "xiaohong", (void*)999);
	hash_set(t, "xiaowang", (void*)39);
	hash_set(t, "xiaoqiu", (void*)30);
	hash_set(t, "xiaohu", (void*)20);
	//����
	int ret = (int)hash_find(t, "xiaoming");
	printf("xiaoming=%d\n", ret);
	ret = (int)hash_find(t, "xiaohong");
	printf("xiaohong=%d\n", ret);
	//�Ҳ���
	ret = (int)hash_find(t, "xiaozhang");
	printf("xiaozhang=%d\n", ret);
	/*
	//�������������Ҫ�ر��������hash_node�ṹ�����ӳ�Ա��Ҳ����ʹ����key���void*��������
	hash_insert(t, "xiaoming_address", (void*)"shanghai");
	char* address = (void*)hash_find(t, "xiaoming_address");
	printf("xiaoming_address=%s\n", address);
	*/
	//����keyɾ�����и�key��Ӧ��ֵ��ͨ��hash_insert�����û�и��ǣ�
	hash_delete(t, "xiaoming");
	ret = (int)hash_find(t, "xiaoming");
	printf("xiaoming=%d\n", ret);

	show_all(t);
	//ɾ������hash��
	destroy_hash_table(t);
}