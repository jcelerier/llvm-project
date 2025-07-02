/// Ensure that profi flag is enabled by default in frontend for SamplePGO

// Target specific checks:
// RUN: %clang --target=x86_64 -c -fprofile-sample-use=/dev/null -### %s 2>&1 | FileCheck %s
// RUN: %clang --target=AArch64 -c -fprofile-sample-use=/dev/null -### %s 2>&1 | FileCheck %s

// Target agnostic checks:
// RUN: %clang -c -fprofile-sample-use=/dev/null -### %s 2>&1 | FileCheck %s
// RUN: %clang -c -fsample-profile-use-profi -fprofile-sample-use=/dev/null -### %s 2>&1 | FileCheck %s
// RUN: %clang -c -fno-sample-profile-use-profi -fsample-profile-use-profi -fprofile-sample-use=/dev/null -### %s 2>&1 | FileCheck %s

// Cases where profi flag is explicitly disabled:
// RUN: %clang -c -### %s 2>&1 | FileCheck %s --check-prefixes=CHECK-NO-PROFI
// RUN: %clang -c -fno-sample-profile-use-profi -fprofile-sample-use=/dev/null -### %s 2>&1 | FileCheck %s --check-prefixes=CHECK-NO-PROFI
// RUN: %clang -c -fsample-profile-use-profi -fno-sample-profile-use-profi -fprofile-sample-use=/dev/null -### %s 2>&1 | FileCheck %s --check-prefixes=CHECK-NO-PROFI


// CHECK: "-mllvm" "-sample-profile-use-profi"
// CHECK-NO-PROFI-NOT: "-sample-profile-use-profi"
