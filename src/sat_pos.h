#pragma once

//double A = 0;// �볤�ᣨ3��4��
//double toe = 0; // �����ο�ʱ�̣�4��1��
//double t = 0; // ������ָ��ʱ��
//double delta_N = 0; // ƽ�˶��2��3��
//double M0 = 0; // �ο���Ԫƽ����ǣ�2��4��
//double e = 0; // ƫ���ʣ�3��2��
//double omega_earth = 0; // ������ת���ٶ�
//double omega0 = .835906122525D + 00; // ���ܳ�ʼ��Ԫ��������ྭ��4��3��
//double omega = .101794964119D + 01; // ���ص�Ǿࣨ5��3��
//double omega_DOT = -.837356307823D - 08; // ������ྭ�仯�ʣ�5��4��
//double i0 = .958243252552D + 00; // �����ǣ�5��1��
//double IDOT = .503592405216D - 10; // �����Ǳ仯�ʣ���delta_i0 / delta_t��6��1��
//double Cis = .614672899246D - 07; // �����ǵ����ҵ������������������ȣ���4��4��
//double Cic = -.800937414169D - 07; // �����ǵ����ҵ������������������ȣ���4��2��
//double Cus = .462494790554D - 05; // γ�ȷ��ǵ����ҵ������������������ȣ���3��3��
//double Cuc = -.198744237423D - 05; // γ�ȷ��ǵ����ҵ������������������ȣ���3��1��
//double Crs = -.405312500000D + 02; // ����뾶�����ҵ���������������m����2��2��
//double Crc = .288406250000D + 03; // ����뾶�����ҵ���������������m����6��2��
//double GM = 3.9860047e14; // ���������������趨ֵΪ 3.9860047D + 14
//
//% ����ƽ���˶����ٶ� n0
//n0 = sqrt(GM / (A * A * A));
//% ��������������ο���Ԫ��ʱ�� tk�������жϣ�
//tk = t - toe;
//if tk > 302400
//tk = tk - 608400;
//end
//if tk < -302400
//    tk = tk + 608400;
//end
//% ��ƽ���˶����ٶȽ��и��� n
//n = n0 + delta_N;
//% ����ƽ����� Mk
//Mk = M0 + n * tk;
//% ����ƫ����� Ek
//syms Ek;
//[Ek] = vpasolve(Mk == Ek - e * sin(Ek));
//% ���������� f
//f = atan2((sqrt(1 - e * e) * sin(Ek)) / (1 - e * cos(Ek)), (cos(Ek) - e) / (1 - e * cos(Ek)));
//% ���������Ǿ� u'
//u_discard = f + omega;
//% ���������Ǿ������ ��uk���򾶸����� ��rk�������Ǹ����� ��ik
//sigma_uk = Cus * sin(2 * u_discard) + Cuc * cos(2 * u_discard);
//sigma_rk = Crs * sin(2 * u_discard) + Crc * cos(2 * u_discard);
//sigma_ik = Cis * sin(2 * u_discard) + Cic * cos(2 * u_discard);
//% ���������������Ǿ� uk���� rk �͹����� ik
//uk = u_discard + sigma_uk;
//rk = A * (1 - e * cos(Ek)) + sigma_rk;
//ik = i0 + sigma_ik + IDOT * tk;
//% ���������ڹ��ƽ���ϵ�λ��(xk, yk)
//Xk = rk * cos(uk);
//Yk = rk * sin(uk);
//% ���������������㾭�� Lk
//Lk = omega0 + (omega_DOT - omega_earth) * t - omega_DOT * toe;
//% ���������ڵ�������ϵ�µ����꣨X, Y, Z��
//X = Xk * cos(Lk) - Yk * cos(ik) * sin(Lk)
//Y = Xk * sin(Lk) + Yk * cos(ik) * cos(Lk)
//Z = Yk * sin(ik)