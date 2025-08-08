define i32 @main() {
entry:
	%var1 = alloca i32, align 4
	%var2 = alloca i32, align 4
	%0 = add i32 0, 1
	store i32 %0, ptr %var2, align 4;
	%1 = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.0, ptr noundef %var1)
	br label %Label0

Label0:
	%2 = load i32, i32* %var1, align 4
	%3 = add i32 0, 1
	%4 = icmp sgt i32 %2, %3
	br i1 %4, label %Label2, label %Label1
Label2:
	%5 = load i32, i32* %var2, align 4
	%6 = load i32, i32* %var1, align 4
	%7 = mul i32 %5, %6
	store i32 %7, ptr %var2, align 4;
	%8 = load i32, i32* %var1, align 4
	%9 = add i32 0, 1
	%10 = sub i32 %8, %9
	store i32 %10, ptr %var1, align 4;
br label %Label0

Label1:
	%11 = load i32, i32* %var2, align 4
	%12 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %11)
	%13 = add i32 0, 0
	ret i32 %13

}




declare i32 @printf(ptr noundef, ...) #1
declare i32 @__isoc99_scanf(ptr noundef, ...) #1

@.str.0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [14 x i8] c"Fatorial: %d\0A\00", align 1
