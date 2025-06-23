define i32 @main() {
entry:
	%var1 = alloca float, align 4
	%0 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.0, ptr noundef %var1)
	%var2 = alloca float, align 4
	%1 = load float, float* %var1, align 4
	%2 = fadd float 0.0, 9.000000
	%3 = fmul float %1, %2
	%4 = fadd float 0.0, 5.000000
	%5 = fdiv float %3, %4
	%6 = fadd float 0.0, 32.000000
	%7 = fadd float %5, %6
	store float %7, ptr %var2, align 4;
	%8 = load float, float* %var1, align 4
	%9 = fpext float %8 to double
%10 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, double noundef %9)
	%11 = load float, float* %var2, align 4
	%12 = fpext float %11 to double
%13 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, double noundef %12)
	%14 = add i32 0, 0
	ret i32 %14

}




declare i32 @printf(ptr noundef, ...) #1
declare i32 @__isoc99_scanf(ptr noundef, ...) #1

@.str.0 = private unnamed_addr constant [3 x i8] c"%f\00", align 1
@.str.1 = private unnamed_addr constant [10 x i8] c"%f °C = \00", align 1
@.str.2 = private unnamed_addr constant [8 x i8] c"%f °F\0A\00", align 1
